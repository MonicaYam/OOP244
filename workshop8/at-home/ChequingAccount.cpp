//Workshop 8 - Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 1.0
// Date: 2019/07/17
// Description:
///////////////////////////////////////////////////

#include "ChequingAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace sict {

	ChequingAccount::ChequingAccount(double balance, double trsFee, double monthlyFee) {
		_currentBalance = 0.0;
		_transactionFee = 0.0;
		_monthlyFee  = 0.0;

		if (balance > 0) {
			_currentBalance = balance;
		}

		if (trsFee > 0) {
			_transactionFee = trsFee;
		}

		if (monthlyFee > 0) {
			_monthlyFee = monthlyFee;
		}
	}

	void ChequingAccount::monthEnd() {
		_currentBalance -= _monthlyFee;
	}

	void ChequingAccount::display(std::ostream&) const {
		cout << "Account type: Chequing" << endl
			 << "Balance: $"<< setprecision(2) << fixed << _currentBalance << endl
			 << "Per Transaction Fee: " << setprecision(2) << fixed << _transactionFee << endl
			 << "Monthly Fee: " << setprecision(2) << fixed << _monthlyFee << endl;
	}



	bool ChequingAccount::credit(double amount) {
		bool result = false;

		if (amount > 0) {
			_currentBalance += amount;
			if (_currentBalance > 0) {
				_currentBalance -= _transactionFee;
				result = true;
			}
		}


		return result;
	}

	bool ChequingAccount::debit(double amount) {
		bool result = false;

		if (amount > 0) {
			_currentBalance -= amount;
			_currentBalance -= _transactionFee;
			result = true;
		}

		return result;
	}


}
