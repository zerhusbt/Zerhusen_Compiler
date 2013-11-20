//*****************************************************************************************
//
//	Filename: Id.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#ifndef ID_H
#define ID_H

#include "../Lexer/Word.h"
#include "../Symbols/Type.h"
#include "../Inter/Expr.h"

class Id : public Expr
{
	public:
		int offset;	// relative address
		Id(Word id, Type p, int b);
}

#endif
