// Workshop 6 - Class with a Resource(in-lab)
// Contact.cpp
// 2019/07/04
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include "Contact.h"

using namespace std;

namespace sict
{
	// Set to safe empty states
	Contact::Contact() {
		_arraySize = 0;
		_contactName[0] = '\0';

	}

	// Gets the data when the object is created: name, phoneNumbers, number of phoneNumbers in the array
	Contact::Contact(const char* name, const long long* phoneNumbers, const int& arraySize)
	{
		_arraySize = arraySize;
		_allPhoneNumbers.reserve(arraySize);
		
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
					if (checkDigit(phoneNumbers[i])) {
						_allPhoneNumbers[k] = phoneNumbers[i];
						k++;
					}
				}
		}
		else{
			_arraySize = 0;
		}
	}

	Contact::~Contact()
	{
		_allPhoneNumbers.clear();
	}

	bool Contact::isEmpty() const
	{
		return _contactName[0] == '\0' && _allPhoneNumbers.empty();
	}

	void Contact::display() const
	{
		int countryCode = 0;
		int areaCode = 0;
		int number = 0;

		if (isEmpty()){
			cout << "Empty contact!" << endl;
		}
		else if (_contactName[0] == '\0' && !_allPhoneNumbers.empty()) {
			cout << "Empty contact!" << endl;

		}
		else{
			//空の場合の対処
			cout << _contactName << endl;

			if (!_allPhoneNumbers.empty()) {

				for (int i = 0; i < (int)_allPhoneNumbers.size(); ++i) {
					countryCode = getCountryCode(_allPhoneNumbers[i]);
					areaCode = getAreaCode(_allPhoneNumbers[i]);
					number = getPhoneNumber(_allPhoneNumbers[i]);

					if (countryCode != 0 && areaCode != 0 && number != 0) {

						cout << "(+" << countryCode << ") " << areaCode << " "
							<< number / 10000 << "-"
							<< setfill('0') << setw(4) << number % 10000 << endl;
					}
				}
			}
		}
	}


	int Contact::getCountryCode(const long long& phoneNumber) const {
		int countryCode = 0;
		int tempCountryCode = phoneNumber / 10000000000;

		if (tempCountryCode < 100 && tempCountryCode > 0) {
			countryCode = tempCountryCode;
		}

		return countryCode;
	}


	int Contact::getAreaCode(const long long& phoneNumber) const {
		int areaCode = 0;
		int tempAreaCode = (phoneNumber % 10000000000) / 10000000;
		int firstDigit = tempAreaCode / 100;

		if (firstDigit != 0) {
			areaCode = tempAreaCode;
		}

		return areaCode;
	}

	int Contact::getPhoneNumber(const long long& phoneNumber) const {
		int number = 0;
		int tempNumber = (phoneNumber % 10000000000) % 10000000;
		int firstDigit = tempNumber / 1000000;

		if (firstDigit != 0) {
			number = tempNumber;
		}

		return number;
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


	Contact& Contact::operator=(const Contact& rContact)
	{
		if (this != &rContact) {
			if (rContact._contactName[0] == '\0') {

				_contactName[0] = '\0';
				_allPhoneNumbers.clear();

			}
			else {
				if (rContact._contactName != nullptr) {
					strncpy(_contactName, rContact._contactName, MAX_CHAR);
					_contactName[MAX_CHAR] = '\0';
				}

				for (int i = 0; i < (int)rContact._allPhoneNumbers.size(); ++i) {
					if (checkDigit(rContact._allPhoneNumbers[i])) {
						_allPhoneNumbers[i] = rContact._allPhoneNumbers[i];
					}
				}
			}
		}

		return *this;
	}

	Contact& Contact::operator+=(const long long& rhs) {
		if (checkDigit(rhs)) {
			_allPhoneNumbers.push_back(rhs);
		}

		return *this;
	}

}
