// Final Project - Milestone 4 - iGood Module
// Version 1.0
// Date	2019-07-25
// iGood.h
//
// For you final test before submission:
//   
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AID_IGOOD_H
#define AID_IGOOD_H

#include<iostream>
#include <fstream>
using namespace std;

namespace aid {
	class iGood {


	public:
		virtual ~iGood()=default;
		virtual fstream& store(std::fstream& file, bool newLine = true) const =0;
		virtual fstream& load(std::fstream& file) = 0;
		virtual ostream& write(std::ostream& os, bool linear) const=0;
		virtual istream& read(std::istream& is) = 0;

		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iGood&) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);
	iGood* CreateProduct(char tag);

}


#endif

