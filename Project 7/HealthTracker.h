#pragma once
#include "Date.h"
#include "FitnessRecord.h"
#include <string>
#include <vector>
class HealthTracker
{
private:
	std::string name;
	char gender;
	Date birthOfDate;
	double height;
	void printMenu();
	int getOption();
	std::vector<FitnessRecord> fitnessData;
	int capacity, days;
public:
	HealthTracker();
	~HealthTracker();
	void inputData();
	void printHistoryData();
	void printRecentData();
	void exectute();
};

