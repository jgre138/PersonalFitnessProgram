#include "HealthTracker.h"
#include "Date.h"
#include "Helper.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void HealthTracker::printMenu() {
	cout << "What would you like to do?\n"
		<< "1 - Add data \n" << "2 - Recent Data \n" << "3 - History Data \n" << "4- Exit Program" << endl;
	cout << "Choice: ";
}
int HealthTracker::getOption() {
	int option = Helper::getInput<int>();
	while (option < 0 || option > 4) {
		cout << "The selected option is invalid, please try again: ";
		option = Helper::getInput<int>();
	}
	return option;
}

HealthTracker::HealthTracker() {
	cout << "Please provide your name, gender(f - female /m - male /o - other), age, and height(m)"
		<< endl
		<< "Name: ";
	name = Helper::getInput<string>();

	cout << "Gender: ";
	gender = Helper::getInput<char>();

	cout << "What is your date of birth? (MM DD YYYY)" << endl;
	int month = Helper::getInput<int>();
	int day = Helper::getInput<int>();
	int year = Helper::getInput<int>();
	Date DOB = Date(month, day, year);
	birthOfDate = DOB;

	cout << "Height: ";
	height = Helper::getInput<double>();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Using  vector so capacity and days are not needed
	//Need to define at least
	capacity = 0; 
	days = 0; 
}
HealthTracker::~HealthTracker() { //using vector so it deletes itself
}
void HealthTracker::inputData() { //Option 1

	cout << "Please enter your weight(kg) from today." << endl;
	cout << "Weight: ";
	double weightRecent = Helper::getInput<double>();

	cout << "Please provide the exercise type and elapsed workout time(minutes): " << endl
		<< "Exercise type: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //fixes issue where it skips the next string input
	string exerciseTypeRecent = Helper::getInput<string>();

	cout << "Duration: ";
	int workoutTimeRecent = Helper::getInput<int>();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "What is the date of your workout ? (MM DD YYYY)" << endl;
	int month = Helper::getInput<int>();
	int day = Helper::getInput<int>();
	int year = Helper::getInput<int>();
	Date date = Date(month, day, year);

	FitnessRecord newRecord = FitnessRecord(weightRecent, exerciseTypeRecent, workoutTimeRecent, date);
	fitnessData.push_back(newRecord);

	cout << "Data Added!" << endl;
}
void HealthTracker::printHistoryData() {
	int size = fitnessData.size();
	if (size > 0) {
		cout << "\t" << name << endl
			<< gender << ", " << birthOfDate.toString() << ", " << height << "m" << endl;
		cout << "Fitness Data (Most recent to oldest): " << endl;
		int totalTime = 0;
		for (int i = (size - 1); i >= 0; i--) {
			FitnessRecord currData = fitnessData.at(i);
			cout << currData.print(height);
			totalTime += currData.getWorkoutTime();
		}

		double bmiOld = fitnessData.front().getWeight() / pow(height, 2);
		double bmiNew = fitnessData.back().getWeight() / pow(height, 2);
		double diff = bmiNew - bmiOld;

		cout << "Change in BMI from oldest entry to most recent entry: "
			<< fixed << setprecision(2) << fabs(diff) << " kg/m^2 ("
			<< (diff >= 0 ? "Increase" : "Decrease") << ")" << endl;
		cout << "Total exercise time: " << totalTime << " mins" << endl;
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}
void HealthTracker::printRecentData() {
	if (fitnessData.size() > 0) {
		FitnessRecord userDataRecent = fitnessData.back();
		cout << "\t" << name << endl
			<< gender << ", " << birthOfDate.toString() << ", " << height << "m" << endl;
		cout << userDataRecent.print(height);
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}
void HealthTracker::exectute() {
	int input = 0;

	cout << "\nWelcome, " << name << "!" << endl;

	do {
		printMenu();
		input = getOption();
		switch (input) {
		case 1:
			inputData();
			break;
		case 2:
			printRecentData();
			break;
		case 3:
			printHistoryData();
			break;
		case 4:
			cout << "Ending program, Goodbye!" << endl;
			break;
		}
		cout << '\n' << endl;
	} while (input != 4);
}
