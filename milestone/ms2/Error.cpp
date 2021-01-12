// Final Project Milestone 2 - Error Class
// Version 1.0
// Error.cpp
// Date	2019-07-11
//
// For you final test before submission:
//  
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include <cstring>

using namespace std;

namespace aid {
	/*** Constractor and Deconstructor***/
	Error::Error(const char* errorMessage) {
		if (errorMessage != nullptr && errorMessage[0] != '\0') {
			int msgLength = strlen(errorMessage) ;

			_msg = new char[msgLength + 1];
			strncpy(_msg, errorMessage, msgLength);
			_msg[msgLength] = '\0';
			
		}
		else {
			_msg = nullptr;
		}

	}

	Error::~Error() {
		if (_msg != nullptr) {
			delete[] _msg;
		}

	}

	void  Error::clear() {
		if (_msg != nullptr) {
			setEmptyState();
		}
	}

	bool  Error::isClear() {
		bool result = false;

		if (_msg == nullptr || _msg[0] == '\0') {
			result = true;
		}

		return result;

	}

	void Error::message(const char* str) {

		setEmptyState();
		if (str != nullptr) {
			int strLength = strlen(str);

			_msg = new char[strLength + 1];

			strncpy(_msg, str, strLength);
			_msg[strLength] = '\0';
		}
	}
	const char* Error::message() const {
		char* tempChar = nullptr;
		if (_msg != nullptr) {
			int length = strlen(_msg);
			tempChar = new char[length + 1];

			strncpy(tempChar, _msg, length);
			tempChar[length] = '\0';
		}

		return tempChar;
	}


	std::ostream& operator<<(std::ostream& ostr, Error& rhs) {
		if (rhs.message() != nullptr) {
			ostr << rhs.message();
		}

		return ostr;
	}


	void Error::setEmptyState() {
		delete[] _msg;
		_msg = nullptr;
	}
}
