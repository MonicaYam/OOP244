//Workshop 8 - Virtual Functions and Abstract Base Classes
// File: SavingsAccount.h
// Version: 1.0
// Date: 2019/07/17
// Description:
// 
///////////////////////////////////////////////////

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include "Account.h"
#include <iostream>

namespace sict {
	class SavingsAccount:public Account{
	private:
		double _interestRate;
	
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;

	};
}
#endif

