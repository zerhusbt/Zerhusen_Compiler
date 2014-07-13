//*****************************************************************************************
//
//	Filename: Node.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 11/22/2013
//	Last Modified: 11/22/2013
//
//*****************************************************************************************

#include "Node.h"

int Node::labels = 0;

Node::Node()
{
	lexline = Lexer::line;
}

void Node::error(std::string s)
{
	std::cout<<"near line "<<lexline<<": "<<s<<std::endl;
}

int Node::newlabel()
{
	return ++labels;
}

void Node::emitlabel(int i)
{
	std::cout<<'L'<<i<<':';
}

void Node::emit(std::string s)
{
	std::cout<<'\t'<<s<<std::endl;
}
