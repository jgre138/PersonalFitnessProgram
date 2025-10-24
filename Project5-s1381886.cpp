/*
	Project 5 by Jennifer Greene

	This is a personal fitness application that records your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.The user can log the exercise they did for the day 
	and the duration of the workout.
	Update (9/17) : Added verification for most of the inputs giving an error message. Updated some of the 
	print statements to look nicer
	Update (9/22) : Made methods to simplify code. Added switch case in a do while for users to choose what
	they would like to do. Added spacing to printed text to make it look nicer.
	Update (9/25) : Made getNum() generic so that it can work with any number.
	Upadate (10/3) : Made functions for several aspects of the program. Made all the verification its own 
	function. Fitness data now can have history.
	Update (10/23) : Added dynamic arrays to store fitness data. Resizing function to increase array size
	when needed. Added calculation for change in BMI and total exercise time in history data.

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
template <>
char getInput() //function overloading so that it does something specific for other types
{
	char value;
	cin >> value;
	while (value != 'f' && value != 'm' && value != 'o' 
		&& value != 'F' && value != 'M' && value != 'O') // allows for uppercase and lowercase
	{
		cout << "Invalid gender, please try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> value;
	}
	return value;
}

template <>
string getInput()
{
	string data;
	getline(cin, data);
	while (cin.fail())
	{
		cout << "Invalid input, please try again: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		getline(cin, data);
	}
	return data;
}

template <typename T>
T* resizeArray(T* arr, int oldSize)
{
	T* newArr = new T[oldSize + 1];
	for (int i = 0; i < oldSize; ++i) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	return newArr;
}

void getBasicInfo(string& name, char& gender, int& age, double& height)
{
	cout << "Please provide your name, gender(f - female /m - male /o - other), age, and height(m)"
		<< endl
		<< "Name: ";
	name = getInput<string>();

	cout << "Gender: ";
	gender = getInput<char>();

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
	int option = getInput<int>();
	while (option < 0 || option > 4) {
		cout << "The selected option is invalid, please try again: ";
		option = getInput<int>();
	}
	return option;
}

void inputData(double*& weight, string*& exerciseType, int*& workoutTime , int& size) //(Option1) 
{
	weight = resizeArray(weight, size);
	exerciseType = resizeArray(exerciseType, size);
	workoutTime = resizeArray(workoutTime, size);
	size++; // since all three will be resized, it will count up one. 
			//The size is the same for all three arrays.


	cout << "Please enter your weight(kg) from today." << endl;
	cout << "Weight: ";
	double weightRecent = getInput<double>();

	cout << "Please provide the exercise type and elapsed workout time(minutes): " << endl
		<< "Exercise type: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //fixes issue where it skips the next string input
	string exerciseTypeRecent = getInput<string>();

	cout << "Duration: ";
	int workoutTimeRecent = getInput<int>();

	weight[size - 1] = weightRecent;
	exerciseType[size - 1] = exerciseTypeRecent;
	workoutTime[size - 1] = workoutTimeRecent;

	cout << "Data Added!" << endl;
}

void printRecentData(string name, char gender, int age, double height, 
	double* weight, string* exerciseType, int* workoutTime, int& size) //(Option 2)
{
	if (size > 0 && weight[size -1] != 0) {
		cout << "\t" << name << endl
			<< gender << ", " << age << ", " << height << " m" << endl;
		cout << "Weight: " << weight[size -1] << " kg, BMI: " << weight[size - 1] / (height * height) << "kg/m^2" << endl;
		cout << "Exercise: " << exerciseType[size - 1] << "(" << workoutTime[size - 1] << " mins)" << endl;
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}

void printHistoryData(string name, char gender, int age, double height, double* weight,
	string* exerciseType, int* workoutTime, int& size) // (Option 3)
{
	if (size > 0 && weight[0] != 0) {
		cout << "\t" << name << endl
			<< gender << ", " << age << ", " << height << " m" << endl;
		cout << "Fitness Data (Most recent to oldest): " << endl;
		int totalTime = 0;
		for (int i = size-1; i > 0; i--) {
			if (weight[i] != 0) {
				cout << "Weight: " << weight[i] << " kg, BMI: " << weight[i] / (height * height) << "kg/m^2" << endl;
				cout << "Exercise: " << exerciseType[i] << "(" << workoutTime[i] << " mins)" << endl;
				totalTime += workoutTime[i];
			}
		}

		double diffenceBMI = (weight[size - 1] / (height * height)) - (weight[0] / (height * height));
		cout << "Change in BMI from oldest entry to most recent entry: "
			<< diffenceBMI << " kg/m^2" << endl;
		cout << "Total exercise time: " << totalTime << " mins" << endl;
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}


//MAIN
int main()
{
	//Variables
	const int OPTION_LIM = 4;
	int size = 0;
	string name = "n/a";
	char gender = 'n';
	int age = 0, input = 0;
	double height = 0;

	//Dynamic Arrays
	string* exerciseType = new string[size];
	int* workoutTime = new int[size];
	double* weight = new double[size];

	//Main Start!!
	getBasicInfo(name, gender, age, height);
	
	cout << "\nWelcome, " << name << "!" << endl;
	
	do {
		printMenu();
		input = getOption();
		switch (input) {
		case 1:
			inputData(weight, exerciseType, workoutTime, size);
			break;
		case 2:
			printRecentData(name, gender, age, height, weight, exerciseType, workoutTime, size);
			break;
		case 3:
			printHistoryData(name, gender, age, height, weight, exerciseType, workoutTime, size);
			break;
		case 4:
			cout << "Ending program, Goodbye!" << endl;
			break;
		}
		cout << "\n";
	} while (input != OPTION_LIM);

	return 0;
}
