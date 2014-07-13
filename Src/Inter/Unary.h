//*****************************************************************************************
//
//	Filename: Unary.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef UNARY_H
#define UNARY_H

#include "Expr.h"
#include "Op.h"
#include "Temp.h"
#include "../Symbols/Type.h"

class Unary : public Op
{
	public:
		Expr* expr;
		Unary(Token* tok, Expr* x); //constructor
		virtual Expr* gen();
		virtual std::string toString();
};

#endif
