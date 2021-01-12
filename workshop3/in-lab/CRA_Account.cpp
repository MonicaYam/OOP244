/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 3.0
//
// Date: 2019/05/29
//
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name                 Date                      Reason
// 
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (sin >= min_sin && sin <= max_sin) {
			_sin = sin;
                        strcpy(_familyName, familyName);
                        strcpy(_givenName, givenName);
		}
		else {
			_sin = -1;               
                        _familyName[0] = '\0';
                        _givenName[0] = '\0';
		}

	}

	bool  CRA_Account::isEmpty() const {
		bool result = false;
		if (_familyName[0] == '\0' || _givenName[0] == '\0'|| _sin == -1) {
			result = true;
		}
		return result;
	}

	void  CRA_Account::display() const {
		 if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}else{
			cout << "Family Name: " << _familyName << endl;
			cout << "Given Name : " << _givenName << endl;
			cout << "CRA Account: " << _sin << endl;
		}
	}

}
