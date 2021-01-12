// Workshop 6 - Class with a Resource(in-lab)
// Contact.h
// 2019/07/04

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

#include<vector>

using namespace std;
namespace sict
{	
	const int MAX_CHAR = 20;


	class Contact
	{

		char _contactName[MAX_CHAR + 1];
		int _arraySize;
		// 1 or 2 digit
		vector<long long> _allPhoneNumbers;

	public:
		Contact();
		Contact(const char*, const long long*, const int&);
		~Contact();
		void display() const;
		bool isEmpty() const;


		bool checkDigit(const long long& phoneNumber);
		int getCountryCode(const long long& phoneNumber) const;
		int getAreaCode(const long long& phoneNumber) const;
		int getPhoneNumber(const long long& phoneNumber) const;

		Contact& operator=(const Contact& rContact);
		Contact& operator+=(const long long& rhs);
	};
}
#endif
