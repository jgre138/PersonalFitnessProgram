#pragma once
#include <string>

class Date
{
private:
	int day, month, year;
	bool isValid(int month, int day, int year);
public:
	Date();
	Date(int month, int day, int year);
	void setDate(int month, int day, int year);
	int getDay();
	int getMonth();
	int getYear();
	std::string toString();
};

