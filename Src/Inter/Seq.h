//*****************************************************************************************
//
//	Filename: Seq.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/14/2014
//	Last Modified: 04/14/2014
//
//*****************************************************************************************

#ifndef SEQ_H
#define SEQ_H

#include "Stmt.h"

class Seq : public Stmt
{
	public:
		Stmt* stmt1;
		Stmt* stmt2;
		Seq(Stmt* s1, Stmt* s2);	// constructor
		void gen(int b, int a);
};

#endif
