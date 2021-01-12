// Workshop 4 - Constructors - Test Main
// Passenger.cpp
// 2019/06/06
//


// TODO: add your headers here
#include <iostream>
#include <string.h>
#include "Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		_passengerName[0] = '\0';
		_destination[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* passengerName, const char* destination) {
		if ( passengerName == nullptr || destination == nullptr){
			_passengerName[0] = '\0';
			_destination[0] = '\0';
		}
		else {
			strncpy(_passengerName, passengerName, strlen(passengerName));
			_passengerName[max_name_length - 1 ] = '\0';
			strncpy(_destination, destination, strlen(destination));
			_destination[max_name_length -1 ] = '\0';
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
			cout << _passengerName << " - "<< _destination << endl;

		}
	}

}
