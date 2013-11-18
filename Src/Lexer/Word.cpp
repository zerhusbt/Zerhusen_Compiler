//*****************************************************************************************
//
//	Filename: Word.cpp
//	Description: File for Word class used to exend Token Class
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#include "Word.h"

Word::Word(int t, std::string s) : Token(t)
{
	lexeme = s;
	
}

std::string Word::toString() 
{
	return lexeme;
}

std::string Word::tokenType()
{
	return "Word";
}

Word* Word::assign = new Word(Tag::ASSIGN,":=");
Word* Word::equal = new Word(Tag::EQUAL,"==");
Word* Word::notequal = new Word(Tag::NOTEQUAL,"!=");
Word* Word::lte = new Word(Tag::LTE,"<=");
Word* Word::gte = new Word(Tag::GTE,">=");
Word* Word::minus = new Word(Tag::MINUS,"minus");
Word* Word::True = new Word(Tag::TRUE,"true");
Word* Word::False = new Word(Tag::FALSE,"false");
