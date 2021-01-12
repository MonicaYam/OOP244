/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 1.0
// 2019/06/01
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
// 
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include "CRA_Account.h"

using namespace std;

namespace sict {


	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (sinCheck(sin)) {
			_sin = sin;
			strncpy(_familyName, familyName, max_name_length + 1);
			strncpy(_givenName, givenName, max_name_length + 1);

			for (int i = 0; i < max_yrs; ++i) {
				_taxReturnYears[i] = 0;
			}

		}
		else {
			_sin = -1;
			_familyName[0] = '\0';
			_givenName[0] = '\0';
			_taxReturnYears[0] = -1;
		}
	}


	void CRA_Account::set(int year, double balance) {
		int  i = 0;
		//looking for empty element in the array
		while (_taxReturnYears[i] != 0) {
			i++;
		}

		_taxReturnYears[i] = year;
		_balanceOrRefund[i] = balance;

	}

	bool  CRA_Account::isEmpty() const {
		bool result = false;

		if (_familyName[0] == '\0' || _givenName[0] == '\0' || _sin == -1 || _taxReturnYears[0] == -1) {
			result = true;
		}

		return result;
	}

	void  CRA_Account::display() const {
		if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}
		else {
			cout << "Family Name: " << _familyName << endl;
			cout << "Given Name : " << _givenName << endl;
			cout << "CRA Account: " << _sin << endl;

			cout << fixed << setprecision(2);

			for (int i = 0; i < max_yrs; i++) {
				if (_balanceOrRefund[i] > 0 && _balanceOrRefund[i] > 2) {

						cout << "Year (" << _taxReturnYears[i] << ") balance owing: " << _balanceOrRefund[i] << endl;
				}
				else if (_balanceOrRefund[i] < 0 && (_balanceOrRefund[i] * -1) > 2) {

						cout << "Year (" << _taxReturnYears[i] << ") refund due: " << _balanceOrRefund[i] * -1 << endl;
				}
				else {
					cout << "Year (" << _taxReturnYears[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
	}


	bool CRA_Account::sinCheck(int sin) {
		bool result = false;

		int checkDigit; 
		int tempDigit;
		int total;
		int alternates = 0;

		if (sin >= min_sin && sin <= max_sin) {
			for (int i = 8; i >= 0; --i) {
				if (i == 8) {
					checkDigit = sin % 10; //get last degit
				}
				else if (i % 2 == 0) {

					alternates += sin % 10;
				}
				else {
					tempDigit = (sin % 10) * 2;
					alternates += tempDigit % 10;

					if (tempDigit > 9) {
						alternates += tempDigit / 10;
					}
				}

				sin /= 10;
			}

			tempDigit = (alternates / 10) + 1;
			total = (tempDigit * 10) - alternates;

			if (checkDigit == total) {
				result = true;
			}
		}

		return result;

	}

}
