//*****************************************************************************************
//
//	Filename: Id.cpp
//	Description: File for Class Lexer
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#include "Id.h"

Id::Id(Word id, Type p, int b) : Type(id,p)
{
	offset = b;
}
