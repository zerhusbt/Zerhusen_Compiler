//*****************************************************************************************
//
//	Filename: Lexer.h
//	Description: Header file for Class Lexer
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#ifndef LEXER_H
#define LEXER_H

#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <stdio.h>
#include "Tag.h"
#include "Token.h"
#include "Num.h"
#include "Real.h"
#include "Word.h"
#include "../Symbols/Type.h"

class Lexer {
	private:
		char peek;
		//creation of hashtable (map)
		std::map<std::string,Word> words;
	public:
		static int line;
		void reserve(Word t);
		Token* scan();
		void readch();
		bool readch(char c);
		// Constructor
		Lexer();
};

#endif
