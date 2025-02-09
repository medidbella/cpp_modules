#include "Date.hpp"
Date::Date(){
	day = 2;
	month = 1;
	year = 2009;
}

Date::Date(const Date &source){
	day = source.day;
	month = source.month;
	year = source.year;
}

Date::Date(int _day, int _month, int _year){
	day = _day;
	month = _month;
	year = _year;
}

Date &Date::operator=(const Date &source){
	day = source.day;
	month = source.month;
	year = source.year;
	return *this;
}

bool Date::operator<(const Date &source) const{
	if (year != source.year)
		return year < source.year;
	else if (month != source.month)
		return month < source.month;
	return day < source.day;
}

int Date::getDay() const{
	return day;
}

int Date::getMonth() const{
	return month;
}

int Date::getYear() const{
	return year;
}

void Date::operator--(){
	if (day > 1){day--; return;}
	day = 31;
	if (month > 1){month--; return;}
	month = 12;
	year -= 1;
}

std::ostream &operator<<(std::ostream &stream, const Date &data)
{
	stream << data.getYear() << '-' << data.getMonth() << '-' << data.getDay();
	return stream;
}

Date::~Date(){}