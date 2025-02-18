#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <cstdlib>
#include <sstream>
#include <ostream>

class Date
{
	private:
		int day;
		int month;
		int year;
	public:
		Date();
		Date(int _day, int _month, int _year);
		Date(const Date &source);
		Date &operator=(const Date &source);
		bool operator<(const Date &source) const;
		void operator--();
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		~Date();
};

std::ostream &operator<<(std::ostream &stream, const Date &data);
#endif