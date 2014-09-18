//*****************************************************************************************
//
//	Filename: Main.cpp
//	Description: File called to execute compiler
//	Author: Benjamin Zerhusen
//	Date Created: 8/20/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#include "Main.h"

int main (int argc, char* argv[])
{
	char* inputFileName = "test";
	char* outputFileName = "output";

	if (argc == 2)
	{
		inputFileName = argv[1];
	}
	if (argc == 3)
	{
		inputFileName = argv[1];
		outputFileName = argv[2];
	}

	Files* fileHolder = new Files();
	FILE* pInputFile;
	pInputFile = fileHolder->openInputFile(inputFileName);
	FILE* pOutputFile;
	pOutputFile = fileHolder->openOutputFile(outputFileName);
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

		fileHolder->closeInputFile();
		fileHolder->closeOutputFile();
	}


	
	return 0;
}
