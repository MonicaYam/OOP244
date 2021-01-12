/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 2019/05/20
// Description
// Display kingdom name and population
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
	void display(Kingdom& pKingdom) {
		cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
	}

	void display(Kingdom* pKingdom, int count) {
		int total = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		
		for (int i = count-1; i >= 0; --i) {
			cout << i+1 << ". " << pKingdom[i].m_name << ", population " << pKingdom[i].m_population << endl;
			total += pKingdom[i].m_population;
		}


		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}

}

