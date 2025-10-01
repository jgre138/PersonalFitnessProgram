/*
	Project 2 by Jennifer Greene

	This is a personal fitness application that records 
	your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.
	The user can log the exercise they did for the day 
	and the duration of the workout.
	Update (9/17) : Added verification for most of the 
	inputs giving an error message. Updated some of the 
	print statements to look nicer

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


	cout << "Please provide your name, gender(f - female /m - male /o - other), age, height(m), "
		<< "and today's weight(kg)" << endl 
		<< "Name: ";
	getline(cin, name);

	cout << "Gender: ";
	cin >> gender;
	while (gender != 'f' && gender != 'm' && gender != 'o')
	{
		cout << "Invalid gender, please try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> gender;
	}

	cout << "Age: ";
	cin >> age;
	while (cin.fail() || age <= 0 || age > 110)
	{ 
		cout << "Invalid age, please try again: ";
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		cin >> age;
	}

	cout << "Height: ";
	cin >> height;
	while (cin.fail() || height <= 0)
	{
		cout << "Invaild height, please try again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		cin >> height;
	}

	cout << "Weight: ";
	cin >> weight;
	while (cin.fail() || weight <= 0) 
	{
		cout << "Invaild weight, please try again: ";
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		cin >> weight;
	}
	
	cout << "Please provide the exercise type and elapsed workout time(minutes) : " << endl
		<< "Exercise type: ";
	cin.ignore();
	getline(cin, exerciseType);

	cout << "Duration: ";
	cin >>	workoutTime;
	while (cin.fail() || workoutTime <= 0)
	{
		cout << "Invalid time, please try again: ";
		cin.clear(); //rest to be successful state
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		cin >> workoutTime;
	}

	cout << "\t" << name << endl
		<< gender << ", " << age << ", " << height << " m" << endl;
	cout << "Weight: " << weight << " kg, BMI: " << weight / (height * height) << "kg/m^2" << endl;
	cout << "Exercise: " << exerciseType << "(" << workoutTime << " mins)" << endl;

	return 0;
}

