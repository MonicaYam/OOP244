/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
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

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account
	{
		char _familyName[max_name_length + 1] = { '\0' };
		char _givenName[max_name_length + 1] = { '\0' };
		int _sin;
		int _taxReturnYears[max_yrs] = { 0 };
		double _balanceOrRefund[max_yrs];

		bool sinCheck(int sin);

	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;

	};

}



#endif

