//*****************************************************************************************
//
//	Filename: Env.cpp
//	Description: Header file for setting up the environments for symbol tables (chained
//		symbol tables to account for scopes)
//	Author: Benjamin Zerhusen
//	Date Created: 11/16/2013
//	Last Modified: 11/18/2013
//
//*****************************************************************************************

#include "Env.h"

void Env::put(Token w, Id i)
{
	table.insert(std::pair<Token,Id>(w,i));
}

Id* Env::get(Token w)
{
	for(Env* e = this;e != NULL;e = e->prev)
	{
		std::map<Token,Id>::iterator found = e->table.find(w);
		if(found != e->table.end())
		{
			Id* t = &found->second;
			return t
		}
	}
	return NULL;
}

Env::Env(Env* n)
{
	prev = n;
}
