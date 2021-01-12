/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File tools.h
// Version 1.0
// Date 2019/05/16
//
// Description
// This provides prototype for tools.cpp
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef STD_TOOLS_H
#define STD_TOOLS_H

namespace sict {
	// Performs a fool-proof integer entry
	int getInt(int min, int max);

	// Displays the user interface menu
	int menu();
}

#endif
