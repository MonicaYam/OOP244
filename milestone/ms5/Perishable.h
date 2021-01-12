// Final Project - Milestone 4 - iGood Module
// Version 1.0
// Date	2019-07-25
// iGood.h
// For you final test before submission:
//   
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include "iGood.h"
#include<iostream>
#include <fstream>

#include "Date.h"
#include "Good.h"
using namespace std;

namespace aid {

	class Perishable: public Good {
		Date _expiryDate;

	public:
		Perishable();
		fstream& store(std::fstream& file, bool newLine = true) const;
		fstream& load(std::fstream& file) ;
		ostream& write(std::ostream& os, bool linear) const;
		istream& read(std::istream& is);
		const Date& expiry() const;

	};
	iGood* CreateProduct(char tag);

}


#endif

