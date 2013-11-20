//*****************************************************************************************
//
//	Filename: Type.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#ifndef TYPE_H
#define TYPE_H

#include "../Lexer/Word.h"

class Type : public Word
{
	public:
		int width = 0;	// width is used for storage allocation
		// constructor
		Type(std::string s, int tag, int w);
		static bool numeric(Type p);
		static Type max(Type p1, Type p2);
		//objects for the basic types
		static Type* Int;
		static Type* Float;
		static Type* Char;
		static Type* Bool;
}

#endif
