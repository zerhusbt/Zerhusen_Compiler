//*****************************************************************************************
//
//	Filename: Expr.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/27/2013
//	Last Modified: 11/27/2013
//
//*****************************************************************************************

#ifndef EXPR_H
#define EXPR_H

#include "Node.h"
#include "../Lexer/Token.h"
#include "../Symbols/Type.h"

class Expr : public Node
{
	public:
		Token* op;
		Type* type;
		// constructor
		Expr(Token* tok, Type* p);
		virtual Expr* gen();
		virtual Expr* reduce();
		virtual void jumping(int t, int f);
		virtual void emitjumps(std::string test, int t, int f);
		virtual std::string toString();
};

#endif
