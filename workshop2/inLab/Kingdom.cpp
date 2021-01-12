/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 2019/05/23
// Description
// it's for displaying kingdom name and population
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

#include<iostream>
// TODO: include the necessary headers
#include "Kingdom.h"

using namespace std;

// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(Kingdom& pKingdom){
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}

}

