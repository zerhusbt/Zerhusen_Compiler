//*****************************************************************************************
//
//	Filename: Logical.cpp
//	Description: File for ???
//	Author: Benjamin Zerhusen
//	Date Created: 04/03/2014
//	Last Modified: 04/03/2014
//
//*****************************************************************************************

#include "Logical.h"

Logical::Logical(Token* tok, Expr* x1, Expr* x2) : Expr(tok, NULL)
{
	expr1 = x1;
	expr2 = x2;
	type = check(expr1->type, expr2->type);
std::cout<<"The value of expr1->type in Logical() is: "<<expr1->type<<" and expr2->type is: "<<expr2->type<<std::endl;
std::cout<<"The value of Type::Bool is: "<<Type::Bool<<"."<<Type::Int<<"."<<Type::Char<<"."<<Type::Float<<std::endl;
	if(type == NULL)
	{
		error("type error");
	}
}

Type* Logical::check(Type* p1, Type* p2)
{
	if(p1 == Type::Bool && p2 == Type::Bool)
	{
		return Type::Bool;
	}
	else
	{
		return NULL;
	}
}

Expr* Logical::gen()
{
	int f = newlabel();
	int a = newlabel();
	Temp* temp = new Temp(type);
	this->jumping(0,f);

	std::string returnString;
	returnString += temp->toString();
	returnString += " = true";
	emit(returnString);

	returnString = "";
	returnString += "goto L";
	returnString += a;
	emit(returnString);

	emitlabel(f);

	returnString = "";
	returnString += temp->toString();
	returnString += " = false";
	emit(returnString);

	emitlabel(a);
	return temp;
}

std::string Logical::toString()
{
	std::string returnString;
	returnString = expr1->toString();
	returnString += " ";
	returnString += op->toString();
	returnString += " ";
	returnString += expr2->toString();
	return returnString;
}
