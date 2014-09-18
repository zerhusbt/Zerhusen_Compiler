//*****************************************************************************************
//
//	Filename: Files.h
//	Description: Header file for ???
//	Author: Benjamin Zerhusen
//	Date Created: 9/10/2014
//	Last Modified: 9/10/2014
//
//*****************************************************************************************

#ifndef FILES_H
#define FILES_H

#include <iostream>
#include <string>

class Files
{
	public:
		static FILE* pInputFile;
		static FILE* pOutputFile;
		// constructor
		Files();
		FILE* openInputFile(char* inputFileName);
		FILE* openOutputFile(char* outputFileName);
		void writeStringToFile(std::string inputString);
		void writeStringToFile(char* inputString);
		void closeInputFile();
		void closeOutputFile();

};

#endif
