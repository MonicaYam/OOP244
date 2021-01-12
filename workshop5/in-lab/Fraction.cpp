// Workshop 5: operator overloading
// File: Fraction.cpp
// Version: 2.1
// Date: 2019/06/13
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// TODO: insert header files
#include "Fraction.h"
#include <iostream>

using namespace std;
// TODO: continue the namespace

namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		_numerator = 0;
		_denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator) {
		bool result = numerator >= 0 && denominator > 0;
		if (result) {
			_numerator = numerator;
			_denominator = denominator;
			reduce();
		}
		else {
			_numerator = 0;
			_denominator = 0;
		}
	}

	// TODO: implement the max query
	int Fraction::max() const {
		int maxNum;
		if (_numerator > _denominator) {
			maxNum = _numerator;
		}
		else {
			maxNum = _denominator;
		}

		return maxNum;
	}

	// TODO: implement the min query
	int Fraction::min()const {
		int minNum;
		if (_numerator < _denominator) {
			minNum = _numerator;
		}
		else {
			minNum = _denominator;
		}

		return minNum;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int gcdNum = gcd();

		_numerator /= gcdNum;
		_denominator /= gcdNum;
	}

	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if(!isEmpty() && _denominator != 1){
			cout << _numerator << "/" << _denominator;

		}
		else if (!isEmpty() && _denominator == 1) {
			cout << _numerator;
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool result = false;
		if (_numerator == 0 || _denominator == 0) {
			result = true;
		}
		return result;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction temp;
		if (!isEmpty() && !rhs.isEmpty()) {
			temp._numerator = (_numerator * rhs._denominator) + (rhs._numerator * _denominator);
			temp._denominator = _denominator * rhs._denominator;
			temp.reduce();
		}
		else {
			temp = Fraction();
		}

		return temp;
	}
}
