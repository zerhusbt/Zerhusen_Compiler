//*****************************************************************************************
//
//	Filename: Not.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef NOT_H
#define NOT_H

#include "Expr.h"
#include "Logical.h"

class Not : public Logical
{
	public:
		Not(Token* tok, Expr* x2); //constructor
		void jumping(int t, int f);
		std::string toString();
};

#endif
