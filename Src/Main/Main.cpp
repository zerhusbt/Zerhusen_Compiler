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
	FILE* pInputFile;
	pInputFile = fopen("test","r");
	if(pInputFile == NULL)
	{
		perror("Error opening file");
	}
	else
	{
		Lexer* lex = new Lexer(pInputFile);
		Parser* parse = new Parser(lex);
		parse->program();
		cout<<endl;

		/*Lexer* lex = new Lexer(pInputFile);
		Token* pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;
		pMyToken = lex->scan();
		cout<<pMyToken->toString()<<endl;
		cout<<pMyToken->tokenType()<<endl;*/

		fclose(pInputFile);
	}


	
	return 0;
}
