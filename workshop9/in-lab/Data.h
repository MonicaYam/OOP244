#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;


	// max returns the largest item in data
	//
	template <typename T>
	T max(const T* data, int n) {
		T max;
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				max = data[i];
			}
			else if (data[i] > data[i - 1]) {
				max = data[i];
			}
		}

		return max;
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n) {
		T min = 0;
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				min = data[i];
			}
			else if (data[i] < data[i - 1]) {
				min = data[i];
			}
		}

		return min;
	}
        
	// sum returns the sum of n items in data
	//  
	template <typename T>
	T sum(const T* data, int n) {
		T sum;
		for (int i = 0; i < n; ++i) {
			sum += data[i];
		}

		return sum;
	}
   
	// average returns the average of n items in data
	//
	template <typename T>
	double average(const T* data, int n) {
		double average = 0.0;
		for (int i = 0; i < n; ++i) {
			average += data[i];
		}

		return average / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	template <typename T>
	bool read(istream& input, T* data, int n) {
		bool result = true;

		for (int i = 0; i < n && result == true; ++i) {
			input.ignore();
			input >> data[i];
			if (input.fail()) {
				result = false;
			}
		}


		return result;
	}

	// display inserts n items of data into std::cout
	//
	template <typename T>
	void display(const char* name, const T* data, int n) {
		cout.width(20);
		cout << right << name;

		for (int i = 0; i < n; ++i)
		{
			cout.width(15);
			cout << data[i];
		}

		cout << "\n";
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif

