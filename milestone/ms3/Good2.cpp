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
#define _CRT_SECURE_NO_WARNINGS
#include "Good.h"
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

namespace aid {
	/****** Protected Function ******/
	void Good::name(const char* name){
		if (name != nullptr) {
			int length = strlen(name) + 1;
			strncpy(_goodName, name, length);
			_goodName[length] = '\0';
		}
		else {
			delete[] _goodName;
			_goodName = nullptr;
		}
	}

	const char* Good::name() const{
		return _goodName;
	}

	const char* Good::sku() const{
		return _sku;
	}

	const char* Good::unit() const{
		return _unit;
	}

	bool Good::taxed() const{
		return _taxable;
	}

	double Good::itemPrice() const{
		return _singlePrice;
	}

	double Good::itemCost() const{

		double cost = _singlePrice;

		if (_taxable) {
			cost = cost * (1 + tax_rate);
		}

		return cost;
	}

	void Good::message(const char* msg){
			_error.message(msg);
	}
	
	bool Good::isClear() const{
		return _error.message() == nullptr;
	}

	/****** Public Function ******/
	Good::Good(const char type = 'N') {
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

	Good::Good(const char* sku, const char* name, const char* unit, int numOfGoodHand, bool taxStatus, double subTotal, int numOfGoodNeeded) {
		_typeOfGood = 'N';
		if (sku != nullptr) {
			strncpy(_sku, sku, max_sku_length);
			_sku[max_sku_length] = '\0';
		}
		else {
			_sku[0] = '\0';
		}

		if (name != nullptr) {
			int length = strlen(name);
			_goodName = new char[length + 1];
			strncpy(_goodName, name, length);
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
				_goodName = new char[length + 1];
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
		if (_goodName) {
			delete[] _goodName;
		}

		if (_error.message() != nullptr) {
			_error.clear();
		}
	}



	/****** Public Function ******/
	void Good::quantity(int qty){
		if (qty > 0) {
			_goodQtyHand = qty;
		}
	}

	bool Good::isEmpty() const{
		return _sku[0] == '\0' && _unit[0] == '\0' && _goodName == nullptr && _goodQtyHand == 0 && _goodQtyNeeded == 0 &&_singlePrice == 0.0;
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
		file << _typeOfGood 
		     << _sku 
		     << _unit 
		     << _goodName
		     << _goodQtyHand 
		     << _goodQtyNeeded
		     << _singlePrice 
		     <<_taxable;

		if (newLine) {
			file << endl;
		}

		return file;
	}

	fstream& Good::load(fstream& file) {
		Good tempGood;
		tempGood._goodName = new char[max_name_length + 1];

		if (file.is_open()) {
			file >>  tempGood._typeOfGood
			     >> tempGood._sku 
                             >> tempGood._unit 
			     >> tempGood._goodName
			     >> tempGood._goodQtyHand 
			     >> tempGood._goodQtyNeeded 
			     >> tempGood._singlePrice
			     >> tempGood._taxable;
		}

		*this = tempGood;
		delete[] tempGood._goodName;
		return file;
	}

	/****** Protected IOStream Function ******/
	ostream& Good::write(ostream& os, bool linear) const {
		char separator = '|';
		os << _error;

		if (linear) {
			os << setw(max_sku_length) << left << _sku << separator
			   << setw(20) << left << _goodName << separator
			   << setw(7) << right << fixed << setprecision(2) << itemCost() << separator 
			   << setw(4) << right << _goodQtyHand << separator
			   << setw(10) << left << _unit << separator
			   << setw(4) << right << _goodQtyNeeded << separator;
		}
		else {
			os << "Sku: " << _sku << endl;
			os << "Name(no spaces): " <<_goodName << endl;
			os << "Price: " << _singlePrice << endl;

			if (_taxable) {
				os << "Price after tax: " << itemCost() << endl;
			}
			else {
				os << "N/A" << endl;
			}

			os << "Quantity on hand: " << _goodQtyHand << endl
			   << "Quantity needed: " << _goodQtyNeeded << endl;
			
		}
		return os;

	}

	istream& Good::read(istream& is) {
		char sku[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		char taxAnswer;
		bool taxable = true;
		double singleUnitPrice = 0.0;
		int goodQtyOnHand = 0;
		int goodQtyNeeded = 0;
		Error error;

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
			is.setstate(ios::failbit);
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
				_goodName[0] = '\0';
			}

			strncpy(_sku, good._sku, strlen(good._sku));
			strncpy(_unit, good._unit, strlen(good._unit));
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

	bool Good::operator>(const Good& rhs) const{
		return strcmp(_goodName, rhs._goodName) > 0;
	}

	int Good::operator+=(int qtyOnHand){
		if (qtyOnHand > 0) {
			_goodQtyHand += qtyOnHand;
		}

		return _goodQtyHand;
	}


	/****** Free Helper Function ******/
	istream& operator>>(std::istream& istr, Good& good){
		good.read(istr);

		return istr;
	}
	ostream& operator<<(std::ostream& ostr, const Good& good){
		good.write(ostr, true);

		return ostr;
	}

	double operator+=(double& cost, const Good& good) {
		cost += good.total_cost();
		return cost;
	}

}
