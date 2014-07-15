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
	static FILE* pInputFile;
	pInputFile = fopen("test","r");
	static FILE* pOutputFile;
	pOutputFile = fopen("output","w");
	if(pInputFile == NULL)
	{
		perror("Error opening input file");
	}
	else if(pOutputFile == NULL)
	{
		perror("Error opening output file");
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
		fclose(pOutputFile);
	}


	
	return 0;
}
