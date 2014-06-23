//*****************************************************************************************
//
//	Filename: Parser.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/15/2014
//	Last Modified: 04/15/2014
//
//*****************************************************************************************

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "../Inter/Access.h"
#include "../Inter/And.h"
#include "../Inter/Arith.h"
#include "../Inter/Break.h"
#include "../Inter/Constant.h"
#include "../Inter/Do.h"
#include "../Inter/Else.h"
#include "../Inter/Expr.h"
#include "../Inter/Id.h"
#include "../Inter/If.h"
#include "../Inter/Logical.h"
#include "../Inter/Not.h"
#include "../Inter/Or.h"
#include "../Inter/Rel.h"
#include "../Inter/Seq.h"
#include "../Inter/Set.h"
#include "../Inter/SetElem.h"
#include "../Inter/Stmt.h"
#include "../Inter/Unary.h"
#include "../Inter/While.h"
#include "../Lexer/Lexer.h"
#include "../Lexer/Num.h"
#include "../Lexer/Real.h"
#include "../Lexer/Tag.h"
#include "../Lexer/Token.h"
#include "../Lexer/Word.h"
#include "../Symbols/Array.h"
#include "../Symbols/Env.h"
#include "../Symbols/Type.h"

class Parser
{
	public:
		Env* top;	// current or top symbol table
		int used;	// storage used for declarations
		Parser(Lexer* l);
		void move();
		void error(std::string s);
		void match(int t);
		void program();
		Stmt* block();
		void decls();
		Type* type();
		Type* dims(Type* p);
		Stmt* stmts();
		Stmt* stmt();
		Stmt* assign();
		Expr* boolean();
		Expr* join();
		Expr* equality();
		Expr* rel();
		Expr* expr();
		Expr* term();
		Expr* unary();
		Expr* factor();
		Access* offset(Id* a);
	private:
		Lexer* lex;	// lexical analyzer for this parser
		Token* look;	// lookahead token
};

#endif
