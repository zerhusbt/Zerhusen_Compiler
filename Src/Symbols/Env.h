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
#include <iostream>
#include "../Lexer/Token.h"
#include "../Inter/Id.h"

class compare
{
	public:
		bool operator() (Token* x,Token* y)
		{
			std::cout<<"We are comparing a "<<x.tokenType()<<" with a "<<y.tokenType()<<std::endl;
			std::cout<<"The value of x is "<<x.toString()<<" and the value of y is "<<y.toString()<<std::endl;
			if(x.tokenType().compare(y.tokenType()) == 0)
			{
				return x.toString().compare(y.toString()) < 0;
			}
			else
			{
				return true;
			}
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
