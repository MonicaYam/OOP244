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
#define _CRT_SECURE_NO_WARNINGS
#include "Good.h"
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

namespace aid {

	/****** Public Function ******/
	Good::Good(const char type) {
		_typeOfGood = type;
		_sku[0]     = '\0';
		_unit[0]    = '\0';
		_goodName   = nullptr;

		_goodQtyHand     = 0;
		_goodQtyNeeded   = 0;
		_singlePrice = 0.0;

		_taxable = true;
		_error.message(nullptr);
	}

	Good::Good(const char* sku, const char* gdName, const char* unit, int numOfGoodHand, bool taxStatus, double subTotal, int numOfGoodNeeded) {
		_typeOfGood = 'N';

		if(sku != nullptr){
			strncpy(_sku, sku, max_sku_length);
			_sku[strlen(sku)] = '\0';
		}
		else{
			_sku[0] = '\0';
		}

		if (gdName != nullptr) {
			int length = strlen(gdName);
			_goodName = new char[length ];
			strncpy(_goodName, gdName, length);
			_goodName[length] = '\0';
		}
		else {
			_goodName = nullptr;
		}

		if (unit != nullptr) {
			strncpy(_unit, unit, max_unit_length);
			_unit[max_unit_length] = '\0';
		}
		else {
			_unit[0] = '\0';
		}

		if (numOfGoodHand > 0) {
			_goodQtyHand = numOfGoodHand;
		}
		else {
			_goodQtyHand = 0;
		}

		_taxable = taxStatus;

		if (subTotal > 0) {

			_singlePrice = subTotal;
		}
		else {

			_singlePrice = 0;
		}


		if (numOfGoodNeeded > 0) {
			_goodQtyNeeded = numOfGoodNeeded;
		}
		else {
			_goodQtyNeeded = 0;
		}

		_error.message(nullptr);
	}

	Good::Good(const Good& good) {
		_typeOfGood = 'N';

		if (this != &good) {
			_typeOfGood = good._typeOfGood;

			if (good._sku != nullptr) {
				strncpy(_sku, good._sku, max_sku_length);
				_sku[max_sku_length] = '\0';
			}
			else {
				_sku[0] = '\0';
			}

			if (good._goodName != nullptr) {
				int length = strlen(good._goodName);
				_goodName = new char[length];
				strncpy(_goodName, good._goodName, length);
				_goodName[length] = '\0';
			}
			else {
				_goodName = nullptr;
			}

			if (good._unit != nullptr) {
				strncpy(_unit, good._unit, max_unit_length);
				_unit[max_unit_length] = '\0';
			}
			else {
				_unit[0] = '\0';
			}

			_goodQtyHand = good._goodQtyHand;	
			_taxable = good._taxable;
			_singlePrice = good._singlePrice;
			_goodQtyNeeded = good._goodQtyNeeded;
;

			if (good._error.message() != nullptr) {
				_error.message(good._error.message());
			}
			else {
				_error.message(nullptr);
			}
		}

	}

	Good::~Good() {
		if (_goodName != nullptr) {
			delete[] _goodName;
		}

		if (_error.message() != nullptr) {
			_error.clear();
		}
	}

	/****** Protected Function ******/
	void Good::name(const char* name) {
		if (_goodName != nullptr) {
			delete[] _goodName;
			_goodName = nullptr;
		}

		if (name != nullptr && _goodName != nullptr) {
			int length = strlen(name) + 1;
			strncpy(_goodName, name, length);
			_goodName[length] = '\0';
		}
	}

	const char* Good::name() const {
		return _goodName;
	}

	const char* Good::sku() const {
		return _sku;
	}

	const char* Good::unit() const {
		return _unit;
	}

	bool Good::taxed() const {
		return _taxable;
	}

	double Good::itemPrice() const {
		return _singlePrice;
	}

	double Good::itemCost() const {

		double cost = _singlePrice;

		if (_taxable) {
			cost = cost * (1 + tax_rate);
		}

		return cost;
	}

	void Good::message(const char* msg) {
		_error.message(msg);
	}

	bool Good::isClear() const {
		return _error.message() == nullptr;
	}


	/****** Public Function ******/
	void Good::quantity(int qty){
		if (qty > 0) {
			_goodQtyHand = qty;
		}
	}

	bool Good::isEmpty() const{
		return _sku[0] == '\0' && _unit[0] == '\0' && _goodName == nullptr ;
	}

	int Good::qtyNeeded() const{
		return _goodQtyNeeded;
	}

	int Good::quantity() const{
		return _goodQtyHand;
	}

	double Good::total_cost() const{
		double totalCost = _singlePrice * _goodQtyHand;

		if (_taxable) {
			totalCost = totalCost * (1 + tax_rate);
		}

		return totalCost;
	}

	/****** Public FileStream Function ******/
	fstream& Good::store(fstream& file, bool newLine) const {
		file << _typeOfGood << ','<< _sku << ',' << _goodName << ',' << _unit << ',' 
			<< _taxable << ',' <<_singlePrice << ',' << _goodQtyHand << ',' << _goodQtyNeeded;

		if (newLine) {
			file << endl;
		}
		return file;
	}

	fstream& Good::load(fstream& file) {
		Good tempGood;
		char comma = ',';
		tempGood._goodName = new char[max_name_length];

		if (file.is_open()) {
			file.getline(tempGood._sku, max_sku_length, comma);
			file.getline(tempGood._goodName, max_name_length, comma);
			file.getline(tempGood._unit, max_unit_length, comma);
			file >> tempGood._taxable;
			file.ignore();
			file >> tempGood._singlePrice;
			file.ignore();
			file >> tempGood._goodQtyHand;
			file.ignore();
			file >> tempGood._goodQtyNeeded;

			*this = tempGood;
		}
		return file;
	}

	/****** Protected IOStream Function ******/
	ostream& Good::write(ostream& os, bool linear) const {
		char separator = '|';

		if (_error.message() != nullptr) {
			os << _error.message();
		}
				
		os.setf(std::ios::fixed);

		if (isClear() && !isEmpty()) {

			if (linear) {
				os.setf(std::ios::left);
				os.width(max_sku_length);
				os << _sku << separator;

				os.width(20);
				os << name() << separator;
				os.unsetf(std::ios::left);
				os.precision(2);
				os.width(7);
				os << itemCost() << separator;
				os.width(4);
				os << _goodQtyHand << separator;


				os.setf(std::ios::left);
				os.width(10);
				os << _unit << separator;

				os.unsetf(std::ios::left);
				os.width(4);
				os << _goodQtyNeeded << separator;
			}
			else {
				os << " Sku: " << _sku << endl;
				if (strlen(_goodName) > 74) {
					os << " Name (no spaces): " << setw(74) << name() << endl;
				}
				else {

					os << " Name (no spaces): " << name() << endl;
				}
				os << " Price: " << _singlePrice << endl;
				os << " Price after tax: ";

				if (_taxable) {
					os << itemCost() << endl;
				}
				else {
					os << " N/A" << endl;
				}

				os << " Quantity on Hand: " << _goodQtyHand << " " << _unit << endl;
				os << " Quantity needed: " << _goodQtyNeeded;

			}
		}
		return os;

	}

	istream& Good::read(istream& is) {
		char sku[max_sku_length];
		char name[max_name_length];
		char unit[max_unit_length];
		char taxAnswer;
		bool taxable = true;
		double singleUnitPrice = 0.0;
		int goodQtyOnHand = 0;
		int goodQtyNeeded = 0;
		Error error = Error();

		cout << " Sku: ";
		is >> sku;
		cout << " Name (no spaces): ";
		is >> name;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> taxAnswer;

		if (taxAnswer == 'n' || taxAnswer == 'N') {
			taxable = false;
		}
		else if (taxAnswer != 'y' && taxAnswer != 'Y' && taxAnswer != 'n' && taxAnswer != 'N') {
			is.setstate(std::ios::failbit);
			error.message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail()) {
			cout << " Price: ";
			is >> singleUnitPrice;

			if (is.fail()) {
				error.message("Invalid Price Entry");
			}
		}

		if (!is.fail()) {
			cout << " Quantity on hand: ";
			is >> goodQtyOnHand;

			if (is.fail()) {
				error.message("Invalid Quantity Entry");
			}
		}

		if (!is.fail()) {
			cout << " Quantity needed: ";
			is >> goodQtyNeeded;

			if (is.fail()) {
				error.message("Invalid Quantity Needed Entry");
			}

		}

		if (!is.fail()) {
			*this = Good(sku, name, unit, goodQtyOnHand, taxable, singleUnitPrice, goodQtyNeeded);
			if (error.message() != nullptr) {
				_error.message(error.message());

			}
		}
		else {
			*this = Good();
			if (error.message() != nullptr) {
				_error.message(error.message());

			}
		}
		return is;
	}

	/****** Protected Helper Function ******/
	Good& Good::operator=(const Good& good){
		if (this != &good) {
			if (good._goodName != nullptr) {
				int length = strlen(good._goodName);
				_goodName = new char[length + 1];
				strncpy(_goodName, good._goodName, length);
				_goodName[length] = '\0';
			}
			else {
				_goodName = nullptr;
			}

			if(good._sku != nullptr){
				strncpy(_sku, good._sku, max_sku_length);
				_sku[max_sku_length] = '\0';
			}
			
			
			strncpy(_unit, good._unit, max_unit_length);
			_unit[max_unit_length] = '\0';

			_goodQtyHand = good._goodQtyHand;
			_goodQtyNeeded = good._goodQtyNeeded;
			_singlePrice = good._singlePrice;
			_taxable = good._taxable;
			_error = good._error;

		}

		return *this;
	}

	bool Good::operator==(const char* rhs) const{
		return strcmp(_sku, rhs) == 0;
	}

	bool Good::operator>(const char* sku) const{
		int NumOfSku = atoi(_sku);
		int rNumOfSku = atoi(sku);
		bool result = false;

		if (NumOfSku > rNumOfSku) {
					result = true;
		}

		return result;
	}

	bool Good::operator>(const iGood& rhs) const{
		return strcmp(_goodName, rhs.name()) > 0;
	}

	int Good::operator+=(int qtyOnHand){
		if (qtyOnHand > 0) {
			_goodQtyHand += qtyOnHand;
		}

		return _goodQtyHand;
	}


	/****** Free Helper Function ******/
	istream& operator>>(std::istream& istr, iGood& iGood){
		return iGood.read(istr);
	}
	ostream& operator<<(std::ostream& ostr, const iGood& iGood){
		return iGood.write(ostr, true);
	}

	double operator+=(double& cost, const iGood& iGood) {
		cost += iGood.total_cost();
		return cost;
	}

}
