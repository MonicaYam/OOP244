// Final Project - Milestone 3 - Good Module
// Version 1
// Date	2019-07-26
// good.h
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AID_GOOD_H
#define AID_GOOD_H

#include "Error.h"
#include "iGood.h"

namespace aid {

	class Good:public iGood {
	protected:

		Error _error;

	protected:
		void name(const char*);
		void message(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		double itemPrice() const;
		double itemCost() const;
		bool isClear() const;
		bool taxed() const;

	public:
		Good(const char type = 'N');
		Good(const char* sku, const char* name, const char* unit, int numOfGoodHand=0, bool taxStatus=true, double subTotal = 0.0,int numOfGoodNeeded = 0);
		Good(const Good& good); //Copy Constructor
		~Good();

		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		double total_cost() const;

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		Good& operator=(const Good& rhs);
		bool operator==(const char*) const;
		bool operator>(const char*) const;
		bool operator>(const iGood&) const;
		int operator+=(int);
	};

	std::istream& operator>>(std::istream&, iGood&);
	std::ostream& operator<<(std::ostream&, const iGood&);
	double operator+=(double&, const iGood&);
}


#endif

