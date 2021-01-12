//Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Allocater.cpp
// Version: 1.0
// Date: 2019/07/17
// Description:
// Allocate dynamic memory to SavingsAccount
///////////////////////////////////////////////////
#include <cstring>
#include "SavingsAccount.h"

namespace sict{

	const double interestRate = 0.05;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* savingsAccount = nullptr;

		if (strncmp(type, "S", 1) == 0) {
			savingsAccount = new SavingsAccount(balance, interestRate);
		}

		return savingsAccount;
	}


}
