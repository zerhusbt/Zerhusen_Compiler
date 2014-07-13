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

#include "Expr.h"
#include "Op.h"
#include "../Lexer/Word.h"
#include "../Symbols/Type.h"

class Arith : public Op
{
	public:
		Expr* expr1;
		Expr* expr2;
		Arith(Token* tok, Expr* x1, Expr* x2); //constructor
		virtual Expr* gen();
		virtual std::string toString();
};

#endif
