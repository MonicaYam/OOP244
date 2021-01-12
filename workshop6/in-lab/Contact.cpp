// Workshop 6 - Class with a Resource(in-lab)
// Contact.cpp
// 2019/07/04
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict
{
	// Set to safe empty states
	Contact::Contact() {
		_allPhoneNumbers = nullptr;
		_arraySize = 0;
		_contactName[0] = '\0';

	}

	Contact::Contact(const char* name, const long long* phoneNumbers, const int& arraySize)
	{
		_arraySize = arraySize;

		_allPhoneNumbers = new long long[arraySize]();

		if (name != nullptr) {
			strncpy(_contactName, name, MAX_CHAR);
			_contactName[MAX_CHAR] = '\0';
		}
		else {
			_contactName[0] = '\0';
		}

		int k = 0;
		if (phoneNumbers != nullptr){
				for (int i = 0; i < arraySize; i++){
					
					if (checkDigit(phoneNumbers[i])){
						_allPhoneNumbers[k] = phoneNumbers[i];
						k++;
					}
				}
		}
		else{
			_allPhoneNumbers = nullptr;
			_arraySize = 0;
		}
	}

	Contact::~Contact()
	{
		// Deallocate the m_phoneNumbers
		if (_allPhoneNumbers != nullptr){
			delete[] _allPhoneNumbers;
			_allPhoneNumbers = nullptr;
		}

	}

	bool Contact::isEmpty() const
	{
		return _contactName[0] == '\0' && _allPhoneNumbers == nullptr;
	}


	void Contact::display() const
	{
		int countryCode = 0;
		int areaCode = 0;
		int number = 0;

		if (isEmpty()){
			cout << "Empty contact!" << endl;
		}
		else{

			cout << _contactName << endl;
			if (_allPhoneNumbers != nullptr) {

				for (int i = 0; _allPhoneNumbers[i] != 0 && i < _arraySize; i++) {
		
					int tempCountryCode = _allPhoneNumbers[i] / 10000000000;
					if (tempCountryCode < 100 && tempCountryCode > 0) {
						countryCode = tempCountryCode;
					}

					int tempAreaCode = (_allPhoneNumbers[i] % 10000000000) / 10000000;
					int firstDigit = tempAreaCode / 100;

					if (firstDigit != 0) {
						areaCode = tempAreaCode;
					}

					int tempNumber = (_allPhoneNumbers[i] % 10000000000) % 10000000;
					firstDigit = tempNumber / 1000000;

					if (firstDigit != 0) {
						number = tempNumber;
					}

					if (countryCode != 0 && areaCode != 0 && number != 0) {

						cout << "(+" << countryCode << ") " << areaCode << " "
							<< number / 10000 << "-"
							<< setfill('0') << setw(4) << number % 10000 << endl;
					}
				}
			}
		}
	}

	bool Contact::checkDigit(const long long& phoneNumber) {
		long long tempNumber = phoneNumber;
		int digit = 0;

		bool result = false;

		//checkDigit
		while (tempNumber != 0) {
			tempNumber = tempNumber / 10;
			++digit;
		}

		if (digit == 11 || digit == 12) {
			result = true;

		}

		return result;
	}

}
