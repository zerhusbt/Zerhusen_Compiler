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
	FILE* pFile;
	pFile = fopen("test","r");
	if(pFile == NULL)
	{
		perror("Error opening file");
	}
	else
	{
		Lexer* lex = new Lexer(pFile);
		Parser* parse = new Parser(lex);
		parse->program();
		cout<<endl;

		/*Lexer* lex = new Lexer(pFile);
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

		fclose(pFile);
	}


	
	return 0;
}
