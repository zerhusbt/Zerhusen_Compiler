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

class Expr : public Node
{
	public:
		Token* op;
		Type* type;
		// constructor
		Expr(Token* tok, Type* p);
		Expr* gen();
		Expr* reduce();
		void jumping(int t, int f);
		void emitjumps(std::string test, int t, int f);
		std::string toString();
};

#endif
