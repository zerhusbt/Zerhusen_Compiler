//*****************************************************************************************
//
//	Filename: Lexer.cpp
//	Description: File for Class Lexer
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 04/16/2014
//
//*****************************************************************************************

#include "Lexer.h"

int Lexer::line = 1;

void Lexer::reserve(Word* t)
{
	words.insert(std::pair<std::string,Word*>(t->lexeme, t));
}

void Lexer::readch()
{
	peek = getc(fileToLex);
}

bool Lexer::readch(char c)
{
	readch();
	if(peek != c)
	{
		return false;
	}
	peek = ' ';
	return true;
}

Token* Lexer::scan()
{
	// remove whitspace
	for(;;readch())
	{
		if(peek == ' ' || peek == '\t') 
		{
			continue;
		}
		else if(peek == '\n')
		{
			line = line + 1;
		}
		else
		{
			break;
		}
	}
	// recognize composite tokens
	switch(peek)
	{
		case '&':
			if(readch('&'))
			{
				return Word::And;
			}
			else
			{
				Token* t = new Token('&');
				return t;
			}
		case '|':
			if(readch('|'))
			{
				return Word::Or;
			}
			else
			{
				Token* t = new Token('|');
				return t;
			}
		case '=':
			if(readch('='))
			{
				return Word::equal;
			}
			else
			{
				Token* t = new Token('=');
				return t;
			}
		case '!':
			if(readch('='))
			{
				return Word::notequal;
			}
			else
			{
				Token* t = new Token('!');
				return t;
			}
		case '<':
			if(readch('='))
			{
				return Word::lte;
			}
			else
			{
				Token* t = new Token('<');
				return t;
			}
		case '>':
			if(readch('='))
			{
				return Word::gte;
			}
			else
			{
				Token* t = new Token('>');
				return t;
			}
	}
	// read a sequence of digits (ints and floats)
	if(isdigit(peek))
	{
		int v =  0;
		do 
		{
			const char* pPeek = &peek;
			v = 10*v + atoi(pPeek);
			readch();
		} while(isdigit(peek));
		if(peek != '.')
		{
			Num* newNum = new Num(v);
			return newNum;
		}
		float x = v;
		float d = 10;
		for(;;)
		{
			readch();
			if(!isdigit(peek))
			{
				break;
			}
			const char* pPeek = &peek;
			x = x + atoi(pPeek) / d;
			d = d * 10;
		}
		Real* newReal = new Real(x);
		return newReal;
	}
	// analyze reserved words and identifiers
	if(isalpha(peek))
	{
		std::string b;
		do 
		{
			b += peek;
			readch();
		} while(isalnum(peek));
		std::map<std::string,Word*>::iterator it = words.find(b);
		if(it != words.end())
		{
			Word* w = it->second;
			return w;
		}
		Word* newWord = new Word(Tag::ID,b);
		words.insert(std::pair<std::string,Word*>(b,newWord));
		return newWord;
	}
	// return current character as token and reset peek
	Token* t = new Token(peek);
	peek = ' ';
	return t;
}

Lexer::Lexer() // Constructor with no parameters
{
	// initialize line counter and peek variables
	line = 1;
	peek = ' ';
	// reserved words
	Word* ifWord = new Word(Tag::IF, "if");
	reserve(ifWord);
	Word* elseWord = new Word(Tag::ELSE, "else");
	reserve(elseWord);
	Word* whileWord = new Word(Tag::WHILE, "while");
	reserve(whileWord);
	Word* doWord = new Word(Tag::DO, "do");
	reserve(doWord);
	Word* breakWord = new Word(Tag::BREAK, "break");
	reserve(breakWord);
	reserve(Word::True);
	reserve(Word::False);
	reserve(Type::Int);
	reserve(Type::Char);
	reserve(Type::Bool);
	reserve(Type::Float);
}

Lexer::Lexer(FILE* pFile) // Constructor with file pointer to be lexed
{
	// initialize line counter and peek variables
	line = 1;
	peek = ' ';
	// save file pointer
	fileToLex = pFile;
	// reserved words
	Word* ifWord = new Word(Tag::IF, "if");
	reserve(ifWord);
	Word* elseWord = new Word(Tag::ELSE, "else");
	reserve(elseWord);
	Word* whileWord = new Word(Tag::WHILE, "while");
	reserve(whileWord);
	Word* doWord = new Word(Tag::DO, "do");
	reserve(doWord);
	Word* breakWord = new Word(Tag::BREAK, "break");
	reserve(breakWord);
	reserve(Word::True);
	reserve(Word::False);
	reserve(Type::Int);
	reserve(Type::Char);
	reserve(Type::Bool);
	reserve(Type::Float);
}
