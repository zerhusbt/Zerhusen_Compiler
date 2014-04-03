//*****************************************************************************************
//
//	Filename: Arith.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef ARITH_H
#define ARITH_H

#include "../Lexer/Word.h"
#include "../Symbols/Type.h"
#include "../Inter/Expr.h"

class Arith : public Op(tok, NULL)
{
	public:
		Expr* expr1, expr2;
		Arith(Token* tok, Expr* x1, Expr* x2); //constructor
		Expr* gen();
		std::string toString();
};

#endif
