//Workshop 8 - Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: 1.0
// Date: 2019/07/17
// Description:
// 
///////////////////////////////////////////////////

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"
namespace sict {
	class Account : public iAccount {
	protected:
		double _currentBalance;

		double balance() const;
	public:
		Account(double balance = 0.0);
		bool credit(double crd = 0.0);
		bool debit(double);
	};

	iAccount* CreateAccount(const char*, double);

}

#endif

