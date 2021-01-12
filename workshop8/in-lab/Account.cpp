// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 1.0
// Date: 2019/07/17
// Description:
// Account.cpp
///////////////////////////////////////////////////

#include "Account.h"

namespace sict {


	Account::Account(double balance) {
		if (balance > 0) {
			_currentBalance = balance;
		}
		else {
			_currentBalance = 0.0;
		}
	}


	double Account::balance() const {
		return _currentBalance;

	}

	bool  Account::credit(double amount) {
		bool result = false;

		if (amount >= 0) {
			_currentBalance += amount;
			result = true;
		}

		return result;

	}
	bool  Account::debit(double amount ) {
		bool result = false;

		if (amount >= 0) {
			_currentBalance -= amount;
			result = true;
		}

		return result;
	}

}
