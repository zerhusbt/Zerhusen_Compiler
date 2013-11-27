//*****************************************************************************************
//
//	Filename: main.cpp
//	Description: File called to execute compiler
//	Author: Benjamin Zerhusen
//	Date Created: 8/20/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#include "main.h"

int main ()
{
	Lexer* myLexer = new Lexer();
	Token* pMyToken = myLexer->scan();
	cout<<pMyToken->toString()<<endl;
	cout<<pMyToken->tokenType()<<endl;
	pMyToken = myLexer->scan();
	cout<<pMyToken->toString()<<endl;
	cout<<pMyToken->tokenType()<<endl;
	return 0;
}
