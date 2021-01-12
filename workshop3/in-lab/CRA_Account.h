/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 3.0
//
// Date: 2019/05/29
//
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name                 Date                      Reason
// 
///////////////////////////////////////////////////////////
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account
	{
	private:
		char _familyName[max_name_length +1];
		char _givenName[max_name_length +1];
		int _sin;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

	};
}
#endif
