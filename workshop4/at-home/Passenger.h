// Workshop 4 - Constructors - Test Main
// Passenger.h
// 2019/06/06
//
// TODO: add header file guard here

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict {

	const int max_name_length = 18;

	// TODO: define the Passenger class here
	class Passenger
	{
	private:
		char _passengerName[max_name_length + 1];
		char _destination[max_name_length + 1];
		int _yearOfDepature;
		int _monthOfDepature;
		int _dayOfDepature;


	public:

		Passenger();
		Passenger(const char* passengerName, const char* destination);
		Passenger(const char* passengerName, const char* destination, const int& year, const int& month, const int& day);


		bool isEmpty() const;
		void display() const;

		const char* name() const;
		bool canTravelWith(const Passenger& partner) const;
	};


}



#endif

