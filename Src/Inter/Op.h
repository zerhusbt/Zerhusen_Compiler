//*****************************************************************************************
//
//	Filename: Op.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/02/2014
//	Last Modified: 04/02/2014
//
//*****************************************************************************************

#ifndef OP_H
#define OP_H

#include "../Lexer/Word.h"
#include "../Symbols/Type.h"
#include "../Inter/Expr.h"

class Op : public Expr
{
	public:
		Op(Token* tok, Type* p); //constructor
		//add the other stuff here
};

#endif
