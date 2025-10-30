/*
	Project 5 by Jennifer Greene

	This is a personal fitness application that records your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.The user can log the exercise they did for the day 
	and the duration of the workout.
	Changelog on Github Repository: https://github.com/jgre138/PersonalFitnessProgram
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct FitnessData {
	double weight = 0;
	string exerciseType;
	int workoutTime = 0;
};


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

//template <typename T>
//T* resizeArray(T* arr, int oldSize)
//{
//	T* newArr = new T[oldSize * 2];
//	for (int i = 0; i < oldSize; ++i) {
//		newArr[i] = arr[i];
//	}
//	delete[] arr;
//	return newArr;
//}

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

void inputData(vector<FitnessData>*& userData , int& size, int& counter) //(Option1) 
{ 

	cout << "Please enter your weight(kg) from today." << endl;
	cout << "Weight: ";
	double weightRecent = getInput<double>();

	cout << "Please provide the exercise type and elapsed workout time(minutes): " << endl
		<< "Exercise type: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //fixes issue where it skips the next string input
	string exerciseTypeRecent = getInput<string>();

	cout << "Duration: ";
	int workoutTimeRecent = getInput<int>();

	//new input using an object into an object array
	FitnessData newEntry;
	newEntry.weight = weightRecent;
	newEntry.exerciseType = exerciseTypeRecent;
	newEntry.workoutTime = workoutTimeRecent;

	userData->push_back(newEntry);

	counter++; 

	cout << "Data Added!" << endl;
}

void printRecentData(string name, char gender, int age, double height, 
	vector<FitnessData>* userData, int counter) //(Option 2)
{
	FitnessData userDataRecent = userData->at(counter - 1); //check this line
	if (counter > 0) {
		cout << "\t" << name << endl
			<< gender << ", " << age << ", " << height << "m" << endl;
		cout << "Weight: " << userDataRecent.weight << " kg, BMI: " << userDataRecent.weight / (height * height) << "kg/m^2" << endl;
		cout << "Exercise: " << userDataRecent.exerciseType << "(" << userDataRecent.workoutTime << " mins)" << endl;
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}

void printHistoryData(string name, char gender, int age, double height, vector<FitnessData>* userData, int counter) // (Option 3)
{
	if (counter > 0) {
		cout << "\t" << name << endl
			<< gender << ", " << age << ", " << height << "m" << endl;
		cout << "Fitness Data (Most recent to oldest): " << endl;
		int totalTime = 0;
		for (int i = counter -1; i >= 0; i--) {
			FitnessData currData = userData->at(i);
			cout << "Weight: " << currData.weight << " kg, BMI: " << currData.weight / (height * height) << "kg/m^2" << endl;
			cout << "Exercise: " << currData.exerciseType << "(" << currData.workoutTime << " mins)" << endl;
			totalTime += currData.workoutTime;
		}

		double diffenceBMI; 
		// this is to keep the number positive depending on if the number is a increase in bmi or decrease
		if ((userData->at(counter - 1).weight / (height * height)) - ((userData->at(counter - 1).weight) / (height * height)) > 0) {
			diffenceBMI = (userData->at(counter - 1).weight / (height * height)) - (userData->at(0).weight / (height * height));
			cout << "Change in BMI from oldest entry to most recent entry: "
				<< diffenceBMI << " kg/m^2 (Increase)" << endl;
		}
		else {
			diffenceBMI = (userData->at(0).weight / (height * height)) - (userData->at(counter - 1).weight / (height * height));
			cout << "Change in BMI from oldest entry to most recent entry: "
				<< diffenceBMI << " kg/m^2 (Decrease)" << endl;
		}

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
	int size = 7, counter = 0;
	string name = "n/a";
	char gender = 'n';
	int age = 0, input = 0;
	double height = 0;


	//Vector of Fitness Data
	vector<FitnessData>* userData;

	//Main Start!!
	getBasicInfo(name, gender, age, height);
	
	cout << "\nWelcome, " << name << "!" << endl;
	
	do {
		printMenu();
		input = getOption();
		switch (input) {
		case 1:
			inputData(userData, size, counter);
			break;
		case 2:
			printRecentData(name, gender, age, height, userData, counter);
			break;
		case 3:
			printHistoryData(name, gender, age, height, userData, counter);
			break;
		case 4:
			cout << "Ending program, Goodbye!" << endl;
			break;
		}
		cout << endl;
	} while (input != OPTION_LIM);

	return 0;
}
