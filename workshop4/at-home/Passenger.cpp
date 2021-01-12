// Workshop 4 - Constructors - Test Main
// Passenger.h
// 2019/06/06
//

#include <iostream>
#include <string.h>
#include <iomanip> 
#include "Passenger.h"

using namespace std;

namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		_passengerName[0] = '\0';
		_destination[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passengerName, const char* destination) {
		if (passengerName == nullptr || destination == nullptr) {
			_passengerName[0] = '\0';
			_destination[0] = '\0';
		}
		else {
			strncpy(_passengerName, passengerName, max_name_length);
			_passengerName [max_name_length] = '\0';

			strncpy(_destination, destination, max_name_length);
			_destination[max_name_length] = '\0';

			_yearOfDepature = 2019;
			_monthOfDepature = 10;
			_dayOfDepature = 1;
		}

	}
	Passenger::Passenger(const char* passengerName, const char* destination, const int& year, const int& month, const int& day) {
		bool isError = true
			;
		if (passengerName != nullptr && destination != nullptr) {
			if (year >= 2019 && year < 2022 && month > 0 && month < 13 && day > 0 && day < 32) {
				strncpy(_passengerName, passengerName, max_name_length);
				_passengerName[max_name_length] = '\0';

				strncpy(_destination, destination, max_name_length);
				_destination[max_name_length] = '\0';

				_yearOfDepature = year;
				_monthOfDepature =month;
				_dayOfDepature = day;

				isError = false;
			}
		}

		if (isError) {
			_passengerName[0] = '\0';
			_destination[0] = '\0';

		}
	}



	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool result = false;

		if (_passengerName[0] == '\0' || _destination[0] == '\0') {
			result = true;
		}

		return result;
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (isEmpty()) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << _passengerName << " - " << _destination << " on " << _yearOfDepature << "/";
			cout << setfill('0') << setw(2) << _monthOfDepature << "/" << setfill('0') << setw(2) << _dayOfDepature << endl;

		}
	}



	const char* Passenger::name() const {

		return _passengerName;

	}

	bool Passenger::canTravelWith(const Passenger& partner) const {
		bool result = false;

		if (strncmp(_destination, partner._destination, max_name_length) == 0) {
			result = true;
		}

		return result;
	}

	
}
