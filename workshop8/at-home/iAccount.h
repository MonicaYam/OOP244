// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Version: 1.0
// Date: 2019/07/17
// Description:
// iAccount.h interface
///////////////////////////////////////////////////

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include<iostream>
namespace sict {
	class iAccount {
	public:
		//if don't add virtual, compiler doesnt call the destructor of deriverd class for this what become the cause of memory leak.
		// declaration of virtual destructor as working with Implicit definition 
		virtual ~iAccount() = default;

		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0; 
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
	};
	// the prototype for a global helper function 
	iAccount* CreateAccount(const char*, double);
}

#endif

