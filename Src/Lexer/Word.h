//*****************************************************************************************
//
//	Filename: Word.h
//	Description: Header file for Word class used to exend Token Class
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#ifndef WORD_H
#define WORD_H

#include <string>
#include "Token.h"
#include "Tag.h"

class Word : public Token 
{
	public:
		std::string lexeme;
		// Constructor
		Word(int t, std::string s);
		// return value
		virtual std::string toString();
		virtual std::string tokenType();
		
		// lexemes for certain reserved words and composite tokens
		static Word* And;
		static Word* Or;		
		static Word* equal;
		static Word* notequal;
		static Word* lte;
		static Word* gte;
		static Word* minus;
		static Word* True;
		static Word* False;
		static Word* temp;
};

#endif
