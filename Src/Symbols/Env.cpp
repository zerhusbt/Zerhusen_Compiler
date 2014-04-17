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

void Env::put(Token* w, Id* i)
{
std::cout<<"inserting a symbol matched to "<<w->toString()<<" with type: "<<i->type->lexeme<<std::endl;
	table.insert(std::pair<Token,Id>(*w,*i));
}

Id* Env::get(Token* w)
{
std::cout<<"Looking for a token of type "<<w->tokenType()<<std::endl;
	for(Env* e = this;e != NULL;e = e->prev)
	{
		std::map<Token,Id,compare>::iterator found = e->table.find(*w);
		if(found != e->table.end())
		{
			Id* t = &found->second;
			std::cout<<"found a symbol matched to "<<w->toString()<<" with type: "<<t->type->lexeme<<std::endl;	// for debugging
			return t;
		}
	}
	return NULL;
}

Env::Env(Env* n)
{
	prev = n;
}
