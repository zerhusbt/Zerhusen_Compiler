//*****************************************************************************************
//
//	Filename: Env.h
//	Description: File for setting up the environments for symbol tables (chained
//		symbol tables to account for scopes)
//	Author: Benjamin Zerhusen
//	Date Created: 11/16/2013
//	Last Modified: 11/18/2013
//
//*****************************************************************************************

#ifndef ENV_H
#define ENV_H

#include <map>
#include "../Lexer/Token.h"
#include "../Inter/Id.h"

class compare
{
	public:
		bool operator() (const Token* x,const Token* y)
		{
			return x<y;
		}
};

class Env
{
	public:
		void put(Token* w,Id* i);
		Id* get(Token* w);
		// Constructor
		Env(Env* n);
	protected:
		Env* prev;
	private:
		//creation of hashtable (map)
		std::map<Token*,Id*, compare> table;
};

#endif
