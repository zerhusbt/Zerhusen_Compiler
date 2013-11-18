//*****************************************************************************************
//
//	Filename: Tag.h
//	Description: Implements integer constants for tag field of Token
//	Author: Benjamin Zerhusen
//	Date Created: 8/23/2013
//	Last Modified: 11/11/2013
//
//*****************************************************************************************

#ifndef TAG_H
#define TAG_H

class Tag 
{
	public:
		static const int AND = 256;
		static const int ASSIGN = 257;
		static const int BEGIN = 258;
		static const int BOOL = 259;
		static const int CASE = 260;
		static const int CLOSEBRACE = 261;
		static const int CLOSEPAREN = 262;
		static const int COLON = 263;
		static const int COMMA = 264;
		static const int DIVIDE = 265;
		static const int ELSE = 266;
		static const int END = 267;
		static const int ENDOFFILE = 268;
		static const int EQUAL = 269;
		static const int FALSE = 270;
		static const int FLOAT = 271;
		static const int FOR = 272;
		static const int GLOBAL = 273;
		static const int GT = 274;
		static const int GTE = 275;
		static const int ID = 276;
		static const int IF = 277;
		static const int IN = 278;
		static const int INT = 279;
		static const int LT = 280;
		static const int LTE = 281;
		static const int MINUS = 282;
		static const int MULTIPLY = 283;
		static const int NOT = 284;
		static const int NOTEQUAL = 285;
		static const int NUM = 286;
		static const int OPENBRACE = 287;
		static const int OPENPAREN = 288;
		static const int OR = 289;
		static const int OUT = 290;
		static const int PLUS = 291;
		static const int PROCEDURE = 292;
		static const int PROGRAM = 293;
		static const int RETURN = 294;
		static const int SEMICOLON = 295;
		static const int STRING = 296;
		static const int THEN = 297;
		static const int TRUE = 298;
};

#endif
