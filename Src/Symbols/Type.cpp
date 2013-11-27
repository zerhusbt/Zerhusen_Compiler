//*****************************************************************************************
//
//	Filename: Type.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/20/2013
//	Last Modified: 11/20/2013
//
//*****************************************************************************************

#include "Type.h"

// constructor
Type::Type(int tag, std::string s, int w) : Word(tag,s)
{
	width = w;
}

bool Type::numeric(Type* p)
{
	if(p==Type::Char || p==Type::Int || p==Type::Float)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Type* Type::max(Type* p1, Type* p2)
{
	if(!numeric(p1) || !numeric(p2))
	{
		return NULL;
	}
	else if(p1==Type::Float || p2==Type::Float)
	{
		return Type::Float;
	}
	else if(p1==Type::Int || p2==Type::Int)
	{
		return Type::Int;
	}
	else
	{
		return Type::Char;
	}
}

Type* Type::Int = new Type(Tag::BASIC, "int", 4);
Type* Type::Float = new Type(Tag::BASIC, "float", 8);
Type* Type::Char = new Type(Tag::BASIC, "char", 1);
Type* Type::Bool = new Type(Tag::BASIC, "bool", 1);
