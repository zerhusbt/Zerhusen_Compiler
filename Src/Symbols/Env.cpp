//*****************************************************************************************
//
//	Filename: Env.cpp
//	Description: Header file for setting up the environments for symbol tables (chained
//		symbol tables to account for scopes)
//	Author: Benjamin Zerhusen
//	Date Created: 11/16/2013
//	Last Modified: 11/18/2013
//
//*****************************************************************************************

#include "Env.h"

Env* Env::prev = new Env;
