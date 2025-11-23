#include "Date.h"
#include <iostream>
using namespace std;

bool Date::isValid(int month, int day, int year) //redo this??
{
	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// Check for leap year
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		daysInMonth[1] = 29;
	return day <= daysInMonth[month - 1];
}

Date::Date() {
	setDate(1, 1, 2000);
}
Date::Date(int month, int day, int year) { 
	if (isValid(month, day, year)) {
		//Did this because I was taught to always use 
		// mutator functions to assign values in a constructor
		setDate(month, day, year);
	}
	else {
		cout << "Invalid date, returning default date." << endl;
		setDate(1, 1, 2000);
	}

}
void Date::setDate(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}
int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}
string Date::toString() {
	string str = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	return str;
}

