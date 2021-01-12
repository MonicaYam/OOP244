// Final Project - Milestone 4 - iGood Module
// Version 1.0
// Date	2019-07-25
// Perishable.cpp
// For you final test before submission:
//   
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include "Good.h"
#include "Perishable.h"

using namespace std;

namespace aid{
	Perishable::Perishable() : Good('P')
	{
		_expiryDate = Date();
	}

	iGood* CreateProduct(char tag) {
		iGood* gd = nullptr;

		if (tag == 'N' || tag == 'n') {
			gd = new Good();
		}
		else if (tag == 'P' || tag == 'p') {
			gd = new Perishable();
		}

		return gd;
	}


	fstream& Perishable::store(fstream& file, bool newLine) const {

		if (isClear() && !isEmpty()) {
			Good::store(file, false);

			file << ',';
			_expiryDate.write(file);

			if (newLine) {
				file << endl;
			}
		}

		return file;
	}


	fstream& Perishable::load(fstream& file) {

		if (isClear()) {
			Good::load(file);
			file.ignore();
			_expiryDate.read(file);
		}
		return file;
	}

	ostream& Perishable::write(ostream& os, bool linear) const {
		if (_error.message() != nullptr) {
			os << _error.message();
		}

		if (isClear() && !isEmpty()) {
			Good::write(os, linear);

			if (linear) {
				_expiryDate.write(os);
			}
			else {
				
				os << endl << " Expiry date: ";
				_expiryDate.write(os);
			}
		}
		return os;
	}

	istream& Perishable::read(istream& is) {
		Good::read(is);
		Date temp = Date();
		if (!is.fail()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			is >> temp;
			if (temp.bad()) {
				is.setstate(std::ios::failbit);
				if (temp.errCode() == CIN_FAILED) {
					_error.message("Invalid Date Entry");
				}
				else if (temp.errCode() == DAY_ERROR) {
					_error.message("Invalid Day in Date Entry");
				}
				else if (temp.errCode() == MON_ERROR) {
					_error.message("Invalid Month in Date Entry");
				}
				else if (temp.errCode() == YEAR_ERROR) {
					_error.message("Invalid Year in Date Entry");
				}
				else if (temp.errCode() == PAST_ERROR) {
					_error.message("Invalid Expiry in Date Entry");
				}
			}
			else {
				_expiryDate = temp;
			}
		}

		return is;
	}



	const Date& Perishable::expiry() const {
		return _expiryDate;
	}

}
