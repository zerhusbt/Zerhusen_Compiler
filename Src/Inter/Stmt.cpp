//*****************************************************************************************
//
//	Filename: Stmt.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/04/2014
//	Last Modified: 04/04/2014
//
//*****************************************************************************************

#include "Stmt.h"

Stmt::Stmt()
{
	after = 0;
}

void Stmt::gen(int b, int a) // called with labels begin and after
{
	//do nothing
}

Stmt* Stmt::Null = new Stmt();
Stmt* Stmt::Enclosing = Stmt::Null; // used for break stmts
