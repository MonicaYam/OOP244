//Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Allocater.cpp
// Version: 1.0
// Date: 2019/07/17
// Description:
// Allocate dynamic memory to SavingsAccount
///////////////////////////////////////////////////

#include "SavingsAccount.h"
#include "ChequingAccount.h"
#include <cstring>
namespace sict{

	const double interestRate = 0.05;
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* account = nullptr;

		if (strncmp(type, "S", 1) == 0) {
			account = new SavingsAccount(balance, interestRate);
		}
		else if (strncmp(type, "C", 1) == 0) {
			account = new ChequingAccount(balance, transactionFee, monthlyFee);
		}
		return account;
	}


}
