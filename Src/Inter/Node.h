//*****************************************************************************************
//
//	Filename: Node.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/22/2013
//	Last Modified: 11/22/2013
//
//*****************************************************************************************

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "../Lexer/Lexer.h"

class Node
{
	public:
		int lexline;
		// constructor
		Node();
		void error(std::string s);
		static int labels;
		int newlabel();
		virtual void emitlabel(int i);
		virtual void emit(std::string s);
		//virtual ~Node() {}
};

#endif
