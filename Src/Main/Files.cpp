//*****************************************************************************************
//
//	Filename: Files.cpp
//	Description: File called to execute compiler
//	Author: Benjamin Zerhusen
//	Date Created: 9/10/2014
//	Last Modified: 9/10/2014
//
//*****************************************************************************************

#include "Files.h"

Files::Files()
{
	//empty constructor (at least for now)
}

FILE* Files::openInputFile(char* inputFileName)
{
	pInputFile = fopen(inputFileName,"r");
	return pInputFile;
}

FILE* Files::openOutputFile(char* outputFileName)
{
	pOutputFile = fopen(outputFileName,"w");
	return pOutputFile;
}

void Files::closeInputFile()
{
	fclose(pInputFile);
}

void Files::closeOutputFile()
{
	fclose(pOutputFile);
}

FILE* Files::pInputFile = NULL;
FILE* Files::pOutputFile = NULL;
