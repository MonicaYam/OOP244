// Workshop 5: operator overloading
// File: Fraction.h
// Version: 1.1
// Date: 2019/06/13
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables
		int _numerator;
		int _denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

		bool isValueContained(const Fraction& rhs) const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int numerator, int denominator);
		bool isEmpty() const;
		void display() const;

		// TODO: declare the + operator overload
		//function()const can use only member function
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);

		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
	};
}
#endif
