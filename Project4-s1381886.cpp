/*
	Project 4 by Jennifer Greene

	This is a personal fitness application that records your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.The user can log the exercise they did for the day 
	and the duration of the workout.
	Update (9/17) : Added verification for most of the inputs giving an error message. Updated some of the 
	print statements to look nicer
	Update (9/22) : Made methods to simplify code. Added switch case in a do while for users to choose what
	they would like to do. Added spacing to printed text to make it look nicer.
	Update (9/25) : Made getNum() generic so that it can work with any number.
	Upadate (10/7) : Made functions for several aspects of the program.

*/

#include <iostream>
#include <string>
using namespace std;


//FUCNTIONS
template <typename D>
D getInput() 
{
	D value = 0;
	cin >> value;
	while (cin.fail() || value <= 0)
	{
		cout << "Invalid number, please try again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		cin >> value;
	}
	return value;
}

void getBasicInfo(string& name, char& gender, int& age, double& height)
{
	cout << "Please provide your name, gender(f - female /m - male /o - other), age, and height(m)"
		<< endl
		<< "Name: ";
	getline(cin, name);  //QUESTION

	cout << "Gender: ";
	cin >> gender;
	//ASK QUESTION ABOUT THIS
	while (gender != 'f' && gender != 'm' && gender != 'o')
	{
		cout << "Invalid gender, please try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> gender;
	}

	cout << "Age: ";
	age = getInput<int>();

	cout << "Height: ";
	height = getInput<double>();
}


void printMenu() 
{
	cout << "What would you like to do?\n"
		<< "1 - Add data \n" << "2 - Recent Data \n" << "3 - History Data \n" << "4- Exit Program" << endl;
	cout << "Choice: ";
}


int getOption()
{
	return getInput<int>();
}

void inputData(double weight[], string exerciseType[], int workoutTime[] , int size) //(Option1) 
{
	cout << "Please enter your weight(kg) from today." << endl;
	cout << "Weight: ";
	double weightRecent = getInput<double>();

	cout << "Please provide the exercise type and elapsed workout time(minutes): " << endl
		<< "Exercise type: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //fixes issue where it skips the next string input
	string exerciseTypeRecent;
	getline(cin, exerciseTypeRecent); //ASK QUESTION

	cout << "Duration: ";
	int workoutTimeRecent = getInput<int>();

	for (int i = size - 1; i > 0; i--) { // Pushes data to make room at the front of the array
		weight[i] = weight[i - 1];
		exerciseType[i] = exerciseType[i - 1];
		workoutTime[i] = workoutTime[i - 1];
	}

	// inserts at the front of the array (To have it easy to print recent to oldest
	weight[0] = weightRecent;
	exerciseType[0] = exerciseTypeRecent;
	workoutTime[0] = workoutTimeRecent;

	cout << "Data Added!" << endl;
}

void printRecentData(string name, char gender, int age, double height, 
	const double weight[], const string exerciseType[], const int workoutTime[]) //(Option 2)
{
	if (weight[0] != 0) {
		cout << "\t" << name << endl
			<< gender << ", " << age << ", " << height << " m" << endl;
		cout << "Weight: " << weight[0] << " kg, BMI: " << weight[0] / (height * height) << "kg/m^2" << endl;
		cout << "Exercise: " << exerciseType[0] << "(" << workoutTime[0] << " mins)" << endl;
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}

void printHistoryData(string name, char gender, int age, double height, const double weight[],
	const string exerciseType[], const int workoutTime[], int size) // (Option 3)
{
	if (weight[0] != 0) {
		cout << "\t" << name << endl
			<< gender << ", " << age << ", " << height << " m" << endl;
		cout << "Fitness Data (Most recent to oldest): " << endl;
		for (int i = 0; i < size; i++) {
			cout << "Weight: " << weight[i] << " kg, BMI: " << weight[i] / (height * height) << "kg/m^2" << endl;
			cout << "Exercise: " << exerciseType[i] << "(" << workoutTime[i] << " mins)" << endl;
		}
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}

//MAIN

int main()
{
	//Variables (reorganize this)
	const int SIZE = 7, OPTION_LIM = 4;
	string name = "n/a";
	char gender = 'n';
	int age = 0, input = 0;
	double height = 0;
	string exerciseType[SIZE] = { "yes", "no", "maybe", "not sure", "uhh" , "y", "n"};
	int  workoutTime[SIZE] = { 1, 2, 3, 4, 5, 6, 7 };
	double weight[SIZE]= { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 };


	//Main Start!!
	getBasicInfo(name, gender, age, height);
	
	cout << "\nWelcome, " << name << "!" << endl;
	
	do {
		printMenu();
		input = getOption();
		switch (input) {
		case 1:
			inputData(weight, exerciseType, workoutTime, SIZE);
			break;
		case 2:
			printRecentData(name, gender, age, height, weight, exerciseType, workoutTime);
			break;
		case 3:
			printHistoryData(name, gender, age, height, weight, exerciseType, workoutTime, SIZE);
			break;
		case 4:
			cout << "Ending program, Goodbye!" << endl;
			break;
		default:
			cout << "The selected option is invalid, please try again: ";
			input = getOption();
		}
		cout << "\n";
	} while (input != OPTION_LIM);

	return 0;
}

