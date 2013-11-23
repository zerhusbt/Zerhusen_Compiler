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

class Node
{
	public:
		int lexline;
		// constructor
		Node();
		void error(std::string s);
		static int labels;
		int newlabel();
		void emitlabel(int i);
		void emit(std::string s);
}


#endif
