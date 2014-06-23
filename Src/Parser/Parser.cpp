//*****************************************************************************************
//
//	Filename: Parser.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/15/2014
//	Last Modified: 04/15/2014
//
//*****************************************************************************************

#include "Parser.h"

Parser::Parser(Lexer* l)
{
	top = NULL;
	used = 0;
	lex = l;
	move();
}

void Parser::move()
{
	look = lex->scan();
}

void Parser::error(std::string s)
{
	std::cout<<"near line "<<lex->line<<": "<<s<<std::endl;
}

void Parser::match(int t)
{
	if(look->tag == t)
	{
		move();
	}
	else
	{
		error("syntax error");
	}
}

void Parser::program()	// program -> block
{
	Stmt* s = block();

	int begin = s->newlabel();
	int after = s->newlabel();
	s->emitlabel(begin);
	s->gen(begin, after);
	s->emitlabel(after);
}

Stmt* Parser::block()	// block -> {decls stmts}
{
	match('{');

	Env* savedEnv = top;
	top = new Env(top);

	decls();
	Stmt* s = stmts();

	match('}');
	top = savedEnv;
	
	return s;
}

void Parser::decls()
{
	while(look->tag == Tag::BASIC)	// D -> type ID ;
	{
		Type* p = type();
		Token* tok = look;
		match(Tag::ID);
		match(';');
		Id* id = new Id((Word*)tok, p, used);
		top->put(tok, id);
		used = used + p->width;
	}
}

Type* Parser::type()
{
	Type* p = (Type*)look;	// expect look->tag == Tag::BASIC
	match(Tag::BASIC);
	if(look->tag != '[')
	{
		return p;	// T -> basic
	}
	else
	{
		return dims(p);	// return array type
	}
}

Type* Parser::dims(Type* p)
{
	match('[');
	Token* tok = look;
	match(Tag::NUM);
	match(']');
	if(look->tag == '[')
	{
		p = dims(p);
	}
	Array* returnArray = new Array(((Num*)tok)->value, p);
	return returnArray;
}

Stmt* Parser::stmts()
{
	if(look->tag == '}')
	{
		return Stmt::Null;
	}
	else
	{
		Stmt* returnStmt = new Seq(stmt(), stmts());
		return returnStmt;
	}
}

Stmt* Parser::stmt()
{
	Expr* x;
	Stmt* s1;
	Stmt* s2;
	Stmt* savedStmt;	// save enclosing loop for breaks

	Else* returnElse;
	While* whilenode;
	Do* donode;
	Break* returnBreak;

	switch(look->tag)
	{
		case ';':
			move();
			return Stmt::Null;
		case Tag::IF:
			match(Tag::IF);
			match('(');
std::cout<<"Beginning of formation of if condition"<<std::endl;
			x = boolean();
std::cout<<"End of formation of if condition"<<std::endl;
			match(')');
			s1 = stmt();
			if(look->tag != Tag::ELSE)
			{
std::cout<<"We have entered the part where a new If() is formed"<<std::endl;
				If* returnIf = new If(x, s1);
				return returnIf;
			}
			match(Tag::ELSE);
			s2 = stmt();
			returnElse = new Else(x, s1, s2);
			return returnElse;
		case Tag::WHILE:
			whilenode = new While();
			savedStmt = Stmt::Enclosing;
			Stmt::Enclosing = whilenode;
			match(Tag::WHILE);
			match('(');
			x = boolean();
			match(')');
			s1 = stmt();
			whilenode->init(x, s1);
			Stmt::Enclosing = savedStmt;	// reset Stmt::Enclosing
			return whilenode;
		case Tag::DO:
			donode = new Do();
			savedStmt = Stmt::Enclosing;
			Stmt::Enclosing = donode;
			match(Tag::DO);
			s1 = stmt();
			match(Tag::WHILE);
			match('(');
			x = boolean();
			match(')');
			match(';');
			donode->init(s1, x);
			Stmt::Enclosing = savedStmt;	// reset Stmt::Enclosing
			return donode;
		case Tag::BREAK:
			match(Tag::BREAK);
			match(';');
			returnBreak = new Break();
			return returnBreak;
		case '{':
			return block();
		default:
			return assign();
	}
}

Stmt* Parser::assign()
{
	Stmt* stmt;
	Token* t = look;
	match(Tag::ID);
	Id* id = top->get(t);
	if(id == NULL)
	{
		std::string errorString;
		errorString += t->toString();
		errorString += " undeclared";
		error(errorString);
	}
	if(look->tag == '=')	// S -> id = E
	{
		move();
		stmt = new Set(id, boolean());
	}
	else			// S -> L = E
	{
		Access* x = offset(id);
		match('=');
		stmt = new SetElem(x, boolean());
	}
	match(';');
	return stmt;
}

Expr* Parser::boolean()
{
	Expr* x = join();
//std::cout<<"In boolean() part 1 the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	while(look->tag == Tag::OR)
	{
		Token* tok = look;
		move();
std::cout<<"In boolean() part 2*a the value of x->type is: "<<x->type<<" at line "<<Lexer::line<<std::endl;
		x = new Or(tok, x, join());
	}
//std::cout<<"In boolean() part 2*b the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	return x;
}

Expr* Parser::join()
{
	Expr* x = equality();
//std::cout<<"In join() part 1 the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	while(look->tag == Tag::AND)
	{
		Token* tok = look;
		move();
std::cout<<"In join() part 2*a the value of x->type is: "<<x->type<<" at line "<<Lexer::line<<std::endl;
		x = new And(tok, x, equality());
	}
//std::cout<<"In join() part 2*b the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	return x;
}

Expr* Parser::equality()
{
	Expr* x = rel();
//std::cout<<"In equality() part 1 the value of x->type is: "<<x->type<<" at line "<<Lexer::line<<std::endl;
	while(look->tag == Tag::EQUAL || look->tag == Tag::NOTEQUAL)
	{
		Token* tok = look;
		move();
std::cout<<"In equality() part 2*a the value of x->type is: "<<x->type<<" at line "<<Lexer::line<<std::endl;
		x = new Rel(tok, x, rel());
//std::cout<<"In equality() part 2*b the value of x->expr1->type is: "<<x->expr1->type<<" compared to: "<<Type::Bool<<std::endl;
	}
//std::cout<<"In equality() part 2*c the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	return x;
}

Expr* Parser::rel()
{
	Expr* x = expr();
std::cout<<"In rel() part 1 the value of x->type is: "<<x->type<<", where Type::Int is "<<Type::Int<<std::endl;

	Logical* returnRel;
	Token* tok;
	switch(look->tag)
	{
		case '<':
		case Tag::LTE:
		case Tag::GTE:
		case '>':
			tok = look;
std::cout<<"In rel() the first value of look->tag is: "<<look->tag<<std::endl;
			move();
std::cout<<"In rel() the second value of look->tag is: "<<look->tag<<std::endl;
std::cout<<"In rel() the value of x->type is: "<<x->type<<" at line "<<Lexer::line<<std::endl;
// for the if( 4 >= 5 ) at line 6 of the test program, the value of tok is a token for GTE(263 is tag), the value of x is an expr for the int 4,  
			returnRel = Logical::create(tok, x, expr());
//std::cout<<"In rel() part 2*a the value of returnRel->expr1->type is: "<<returnRel->expr1->type<<" compared to: "<<Type::Bool<<std::endl;
			return returnRel;
		default:
//std::cout<<"In rel() part 2*b the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
			return x;
	}
}

Expr* Parser::expr()
{
	Expr* x = term();
//std::cout<<"In expr() part 1 the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	while(look->tag == '+' || look->tag == '-')
	{
		Token* tok = look;
		move();
		x = new Arith(tok, x, term());
//std::cout<<"In expr() part 2*a the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	}
//std::cout<<"In expr() part 2*b the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	return x;
}

Expr* Parser::term()
{
	Expr* x = unary();
//std::cout<<"In term() part 1 the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	while(look->tag == '*' || look->tag == '/')
	{
		Token* tok = look;
		move();
		x = new Arith(tok, x, unary());
//std::cout<<"In term() part 2*a the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	}
//std::cout<<"In term() part 2*b the value of x->type is: "<<x->type<<" compared to: "<<Type::Bool<<std::endl;
	return x;
}

Expr* Parser::unary()
{
	if(look->tag == '-')
	{
		move();
		Unary* returnUnary = new Unary(Word::minus, unary());
		return returnUnary;
	}
	else if(look->tag == '!')
	{
		Token* tok = look;
		move();
//std::cout<<"In unary() part 1 the value of tok->tag is: "<<tok->tag<<" at line "<<Lexer::line<<std::endl;
		Not* returnNot = new Not(tok, unary());
		return returnNot;
	}
	else
	{
std::cout<<"We have entered into the portion of unary() that was expected"<<std::endl;
		return factor();
	}
}

Expr* Parser::factor()
{
	Expr* x = NULL;
std::cout<<"Within the Parser::factor() function the value of look->tag is: "<<look->tag<<" at line "<<Lexer::line<<std::endl;
std::cout<<"The value of look->toString() at this point is: "<<look->toString()<<std::endl;
	switch(look->tag)
	{
		case '(':
			move();
			x = boolean();
			match(')');
			return x;
		case Tag::NUM:
			x = new Constant(look, Type::Int);
			move();
			return x;
		case Tag::REAL:
			x = new Constant(look, Type::Float);
			move();
			return x;
		case Tag::TRUE:
			x = Constant::True;
			move();
			return x;
		case Tag::FALSE:
			x = Constant::False;
			move();
			return x;
		default:
			error("syntax error");
			return x;
		case Tag::ID:
			std::string s = look->toString();
			Id* id = top->get(look);
			if(id == NULL)
			{
				std::string errorString;
				errorString += look->toString();
				errorString += " undeclared";
				error(errorString);
			}
			move();
			if(look->tag != '[')
			{
				return id;
			}
			else
			{
				return offset(id);
			}
	}
}

Access* Parser::offset(Id* a)	// I -> [E] | [E] I
{
	Expr* i;
	Expr* w;
	Expr* t1;
	Expr* t2;
	Expr* loc;		//inherit id
	
	Type* type = a->type;
	
	match('[');		// first index, I -> [E]
	i = boolean();
	match(']');

	type = ((Array*)type)->of;
	w = new Constant(type->width);
	t1 = new Arith(new Token('*'), i, w);
	loc = t1;
	while(look->tag == '[')		// multi-dimensional I -> [E] I
	{
		match('[');
		i = boolean();
		match(']');
		type = ((Array*)type)->of;
		w = new Constant(type->width);
		t1 = new Arith(new Token('*'), i, w);
		t2 = new Arith(new Token('+'), loc, t1);
		loc = t2;
	}
	Access* returnAccess = new Access(a, loc, type);
	return returnAccess;
}


