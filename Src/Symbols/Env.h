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

class Env
{
	public:
		void put(Token w,Id i);
		Id get(Token w);
		// Constructor
		Env(Env n);
	protected:
		static Env* prev;
	private:
		//creation of hashtable (map)
		std::map<std::string,Word> table;
};

#endif
