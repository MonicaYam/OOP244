// Workshop 4 - Constructors - Test Main
// Passenger.h
// 2019/06/06
//
// TODO: add header file guard here

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict {

	const int max_name_length = 19;

	// TODO: define the Passenger class here
	class Passenger
	{
	private:
		char _passengerName[max_name_length] = { '\0' };
		char _destination[max_name_length] = { '\0' };

	public:
		Passenger();
		Passenger(const char* passengerName, const char* destination);


		bool isEmpty() const;
		void display() const;

	};


}



#endif

