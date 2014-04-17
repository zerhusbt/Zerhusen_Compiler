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
			x = boolean();
			match(')');
			s1 = stmt();
			if(look->tag != Tag::ELSE)
			{
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
	Id* id = top->get(t);	// Something is failing HERE!!!!!!!!!
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
	while(look->tag == Tag::OR)
	{
		Token* tok = look;
		move();
		x = new Or(tok, x, join());
	}
	return x;
}

Expr* Parser::join()
{
	Expr* x = equality();
	while(look->tag == Tag::AND)
	{
		Token* tok = look;
		move();
		x = new And(tok, x, equality());
	}
	return x;
}

Expr* Parser::equality()
{
	Expr* x = rel();
	while(look->tag == Tag::EQUAL || look->tag == Tag::NOTEQUAL)
	{
		Token* tok = look;
		move();
		x = new Rel(tok, x, rel());
	}
	return x;
}

Expr* Parser::rel()
{
	Expr* x = expr();

	Rel* returnRel;
	Token* tok;
	switch(look->tag)
	{
		case '<':
		case Tag::LTE:
		case Tag::GTE:
		case '>':
			tok = look;
			move();
			returnRel = new Rel(tok, x, expr());
			return returnRel;
		default:
			return x;
	}
}

Expr* Parser::expr()
{
	Expr* x = term();
	while(look->tag == '+' || look->tag == '-')
	{
		Token* tok = look;
		move();
		x = new Arith(tok, x, term());
	}
	return x;
}

Expr* Parser::term()
{
	Expr* x = unary();
	while(look->tag == '*' || look->tag == '/')
	{
		Token* tok = look;
		move();
		x = new Arith(tok, x, unary());
	}
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
		Not* returnNot = new Not(tok, unary());
		return returnNot;
	}
	else
	{
		return factor();
	}
}

Expr* Parser::factor()
{
	Expr* x = NULL;
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


