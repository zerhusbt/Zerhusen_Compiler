//*****************************************************************************************
//
//	Filename: Stmt.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#ifndef STMT_H
#define STMT_H


#include "Node.h"

class Stmt : public Node
{
	public:
		Stmt(); //constructor
		static Stmt* Null;
		void gen(int b, int a); //called with labels begin and after
		int after; // saves label after
		static Stmt* Enclosing; //used for break stmts
};

#endif
