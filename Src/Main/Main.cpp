//*****************************************************************************************
//
//	Filename: main.cpp
//	Description: File called to execute compiler
//	Author: Benjamin Zerhusen
//	Date Created: 8/20/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#include "Main.h"

int main (int argc, const char* argv[])
{
	Lexer* lex = new Lexer();
	Parser* parse = new Parser(lex);
	parse->program();
	cout<<endl;

	//Token* pMyToken = lex->scan();
	//cout<<pMyToken->toString()<<endl;
	//cout<<pMyToken->tokenType()<<endl;
	//pMyToken = lex->scan();
	//cout<<pMyToken->toString()<<endl;
	//cout<<pMyToken->tokenType()<<endl;
	
	return 0;
}
