// Final Project Milestone 2 - Error Class
// Version 1.0
// Error.h
// Date	2019-07-11
//
// For you final test before submission:
//  
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AID_ERROR_H
#define AID_ERROR_H

#include<iostream>

namespace aid {
	class Error {
	private:
		char* _msg;
		void setEmptyState();

	public:
		explicit Error(const char* errorMessage = nullptr);
		~Error();
		void clear();
		bool isClear();
		void message(const char* str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream& ostr, Error& error);
}

#endif // !


