//*****************************************************************************************
//
//	Filename: Constant.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Constant.h"

Constant::Constant(Token* tok, Type* p) : Expr(tok, p)
{
	//do nothing here
}

Constant::Constant(int i) : Expr(new Num(i),Type::Int)
{
	//do nothing here
}

void Constant::jumping(int t, int f)
{
	if(this == True && t != 0)
	{
		std::string returnString;
		returnString += " goto L";
		returnString += t;
		emit(returnString);
	}
	else if(this == False && f != 0)
	{
		std::string returnString;
		returnString += " goto L";
		returnString += f;
		emit(returnString);
	}
}

Constant* Constant::True = new Constant(Word::True, Type::Bool);
Constant* Constant::False = new Constant(Word::False, Type::Bool);
