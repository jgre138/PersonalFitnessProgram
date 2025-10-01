/*
	Project 1 by Jennifer Greene

	This is a personal fitness application that records 
	your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.
	The user can log the exercise they did for the day 
	and the duration of the workout.

*/

#include <iostream>
//#include <iomanip>
#include <string>
using namespace std;

int main() 
{
	string name, exerciseType;
	char gender;
	int age, workoutTime;
	double height, weight;


	cout << "Please provide your name, gender, age, hight(m), "
		<< "and today's weight(kg), in that specific order: " << endl;
	cin >> name >> gender >> age >> height >> weight;

	cout << "Please provide the exercise type and elapsed workout time(minutes) : " << endl;
	cin >> exerciseType >> workoutTime;

	cout << "\t" << name << endl
		<< gender << ", " << age << ", " << height << " m" << endl;
	cout << "Weight: " << weight << " kg, BMI: " << weight / (height * height) << "kg/m^2" << endl;
	cout << "Exercise: " << exerciseType << "(" << workoutTime << " mins)" << endl;

	return 0;
}





