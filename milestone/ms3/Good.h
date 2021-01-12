// Final Project - Milestone 3 - Good Module
// Version 3.7
// Date	2018-06-22
// 244_ms3_tester_prof.cpp
// Author	Fardad Soleimanloo, Chris Szalwinski, Cornel
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

namespace aid {
	const int max_sku_length  = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate     = 0.13;

	class Good {
	private:
		char  _typeOfGood;
		char  _sku[max_sku_length + 1];
		char  _unit[max_unit_length + 1];
		char* _goodName;
		
		int _goodQtyHand;
		int _goodQtyNeeded;
		double _singlePrice;
		
		bool _taxable;
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
		Good(const char type);
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
		bool operator>(const Good&) const;
		int operator+=(int);
	};

	std::istream& operator>>(std::istream&, Good&);
	std::ostream& operator<<(std::ostream&, const Good&);
	double operator+=(double&, const Good&);
}


#endif

