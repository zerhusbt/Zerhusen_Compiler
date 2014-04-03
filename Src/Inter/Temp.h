//*****************************************************************************************
//
//	Filename: Temp.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef TEMP_H
#define TEMP_H

#include "../Symbols/Type.h"

class Temp : public Expr(Word->temp, p)
{
	public:
		static int count;
		int number = 0;
		Temp(Type* p);	// constructor
		std::string toString();
};

#endif
