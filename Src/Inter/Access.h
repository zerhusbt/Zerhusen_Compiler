//*****************************************************************************************
//
//	Filename: Access.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#ifndef ACCESS_H
#define ACCESS_H

#include "Op.h"
#include "Id.h"
#include "Expr.h"
#include "../Symbols/Type.h"
#include "../Lexer/Tag.h"

class Access : public Op
{
	public:
		Id* array;
		Expr* index;
		Access(Id* a, Expr* i, Type* p); //constructor
		virtual Expr* gen();
		virtual void jumping(int t, int f);
		virtual std::string toString();
};

#endif
