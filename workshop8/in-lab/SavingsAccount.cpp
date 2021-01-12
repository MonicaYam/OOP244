// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 1.0
// Date: 2019/07/17
// Description:
// SavingsAccount.cpp
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
	SavingsAccount::SavingsAccount(double balance, double rate) {
		_interestRate = 0.0;
		_currentBalance = 0.0;

		if (rate > 0) {
			_interestRate = rate;
		}

		if (balance > 0) {
			_currentBalance = balance;
		}
	}

	void SavingsAccount::monthEnd() {
		double benefit = _currentBalance * _interestRate;
		_currentBalance += benefit;
	}

	void SavingsAccount::display(std::ostream&) const {
		cout << "Account type: Savings" << endl;
		cout << setprecision(2) << fixed << "Balance: $" << _currentBalance << endl;
		cout << setprecision(2) << fixed << "Interest Rate (%): " << _interestRate * 100 << endl;
	}


}
