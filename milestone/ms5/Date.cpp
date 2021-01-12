// Final Project Milestone 1 - Date Module Tester
// Version 1.0
// Date.cpp
// Date	2019-07-10
// Description
// This program test the student implementation of the Date class
// for submission.

// Revision History
// --------------------------------------------------------------
// , Date: 2019/07/10       
/////////////////////////////////////////////////////////////////

#include <iostream>
#include<iomanip>
#include "Date.h"
using namespace std;

namespace aid
{
	// Safe empty state
	Date::Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
		_currentDate = 0;
		_currentErrCode = NO_ERROR;
	}

	// if parameters are valid, it subsitute them to member variable
	Date::Date(int year, int month, int day)
	{
		bool result = false;
		int tempDate = 0;
		int maxDays = mdays(month, year);

		_year = 0;
		_month = 0;
		_day = 0;
		_currentDate = 0;

		if (checkYear(year)) {
			_year = year;
			result = true;
		}

		if (result && checkMonth(month)) {
			_month = month;
		}
		else {
			result = false;
		}

		if (result && checkDay(day, maxDays)){
			_day = day;
		}

		tempDate = (year * 372) + (month * 31) + day;
		
		if (tempDate <= min_date) {
			_currentErrCode = PAST_ERROR;
		}
		else {
			_currentDate = tempDate;
			_currentErrCode = NO_ERROR;
		}
	}

	// returns errCode
	int Date::errCode() const
	{
		return _currentErrCode;
	}

	//it returns true if currentErrCode has errorCode(1-5)
	bool Date::bad() const
	{
		return _currentErrCode != NO_ERROR;
	}


	// returns true if this == rhs
	bool Date::operator==(const Date& rhs) const
	{
		return _currentDate == rhs._currentDate;
	}

	// returns true this != rhs
	bool Date::operator!=(const Date& rhs) const
	{
		return _currentDate != rhs._currentDate;
	}

	// returns true if this < rhs
	bool Date::operator<(const Date& rhs) const
	{
		return _currentDate < rhs._currentDate;
	}

	/*** overload operator ***/
	bool Date::operator>(const Date& rhs) const
	{
		return _currentDate > rhs._currentDate;
	}

	bool Date::operator<=(const Date& rhs) const
	{
		bool result = *this < rhs || *this == rhs;
		return result;
	}


	bool Date::operator>=(const Date& rhs) const
	{
		bool result = *this > rhs || *this == rhs;
		return result;
	}

	/*** read & write ***/
	istream& Date::read(std::istream& istr)
	{
		char slash = '/';
		int tempYear;
		int tempMonth;
		int tempDay;

		istr.clear();

		istr >> tempYear >> slash  >> tempMonth >> slash >> tempDay;

		int tempDate = (tempYear * 372) + (tempMonth * 31) + tempDay;
		int maxDays = mdays(tempMonth, tempYear);

		if (istr.fail()){
			errCode(CIN_FAILED);
		}
		else if (!checkYear(tempYear)){
			errCode(YEAR_ERROR);
		}
		else if (!checkMonth(tempMonth)){
			errCode(MON_ERROR);
		}
		else if (!checkDay(tempDay, maxDays)){
			errCode(DAY_ERROR);
		}
		else if (min_date > tempDate) {
			errCode(PAST_ERROR);
		}
		else {
			_year = tempYear;
			_month = tempMonth;
			_day = tempDay;
			_currentDate = tempDate;

			errCode(NO_ERROR);
		}

		return istr;
	}

	
	ostream& Date::write(std::ostream& ostr) const
	{
		int maxDays = mdays(_month, _year);
		int outputYear = 0;
		int outputMonth = 0;
		int outputDay = 0;

		bool result = false;

		if (checkYear(_year)) {
			outputYear = _year;
			result = true;
		}

		if (result && checkMonth(_month)) {
			outputMonth = _month;
		}
		else {
			result = false;
		}

		if (result && checkDay(_day, maxDays)) {
			outputDay = _day;
		}
		

		ostr << outputYear << '/' << setfill('0') << setw(2) << outputMonth << '/' << setfill('0') << setw(2) << outputDay;
		ostr << setfill(' ');

		return ostr;
	}

	/*** Private Function ***/
	//get max days from each month
	int Date::mdays(int mon, int year) const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode)
	{
		_currentErrCode = errorCode;
	}


	bool Date::checkYear(const int targetYear) const {
		return min_year <= targetYear && max_year >= targetYear;
	}

	bool Date::checkMonth(const int targetMonth) const {
		return 1 <= targetMonth && 12 >= targetMonth;
	}

	bool Date::checkDay(const int targetDay, const int maxDays) const {
		return 1 <= targetDay && maxDays >= targetDay;
	}

	/*** Free Helper Function ***/
	istream& operator>>(istream& istr, Date& date)
	{
		return date.read(istr);
	}

	ostream& operator<<(ostream& ostr, Date& date)
	{
		return date.write(ostr);
	}
}
