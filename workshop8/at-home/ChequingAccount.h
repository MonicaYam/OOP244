//Workshop 8 - Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Version: 1.0
// Date: 2019/07/17
// Description:
// 
///////////////////////////////////////////////////

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H
#include "Account.h"
#include <iostream>

namespace sict {
	class ChequingAccount :public Account {
	private:
		double _transactionFee;
		double _monthlyFee;

	public:
		ChequingAccount(double, double, double);
		void monthEnd();
		void display(std::ostream&) const;

		using Account::credit;
		using Account::debit;
		virtual bool credit(double);
		virtual bool debit(double);

	};
}
#endif

