// Final Project Milestone 1 - Date Module Tester
// Version 1.0
// Date,h
// Date	2019-07-10
// Description
// This program test the student implementation of the Date class
// for submission.

// Revision History
// --------------------------------------------------------------
//, Date: 2019/07/10       
/////////////////////////////////////////////////////////////////

#ifndef AID_DATE_H
#define AID_DATE_H

namespace aid
{

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098; // represents the date 2018/12/30

	class Date
	{
	private:
		#define NO_ERROR   0 //No error -  the date is valid
		#define CIN_FAILED 1 //istream faild on information entry
		#define DAY_ERROR  2 //Day value is invalid
		#define MON_ERROR  3 //Month value is invalid
		#define YEAR_ERROR 4 //Year value is invalid
		#define PAST_ERROR 5 //Date value is invalid

		int _year;  //4digits
		int _month; // 1 to 12
		int _day;   // int between the max number of days in the month
		int _currentDate;

		int _currentErrCode = 0; // NO_ERROR

		//set errCode
		void errCode(int errorCode);

		//check the max days of month
		int mdays(int year, int month) const;

		bool checkYear(const int targetYear) const;
		bool checkMonth(const int targetMonth) const;
		bool checkDay(const int targetDay, const int maxDays) const;

	public:
		Date();
		Date(int year, int month, int day);

		bool bad(void) const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode() const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	//Free Helper Function
	std::ostream& operator<<(std::ostream& ostr, Date&);
	std::istream& operator>>(std::istream& istr, Date&);
}
#endif
