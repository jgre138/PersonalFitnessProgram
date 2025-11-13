/*
	Project 6 by Jennifer Greene

	This is a personal fitness application that records your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.The user can log the exercise they did for the day 
	and the duration of the workout.
	Changelog on Github Repository: https://github.com/jgre138/PersonalFitnessProgram
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct FitnessRecord {
	double weight = 0;
	string exerciseType;
	int workoutTime = 0;
};
// Current program has compile time error. 
// FitnessRecord needs to be defined before it is
// used in the User definition.
struct User {
	string name;
	char gender;
	int age;
	double height;
	vector<FitnessRecord> fitnessData;
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

void getBasicInfo(User& user)
{
	cout << "Please provide your name, gender(f - female /m - male /o - other), age, and height(m)"
		<< endl
		<< "Name: ";
	user.name = getInput<string>();

	cout << "Gender: ";
	user.gender = getInput<char>();

	cout << "Age: ";
	user.age = getInput<int>();

	cout << "Height: ";
	user.height = getInput<double>();

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

double calculateBMI(double weight, double height) 
{
	return weight / (height * height);
}

void inputData(User& user) //(Option1) 
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
	FitnessRecord newEntry;
	newEntry.weight = weightRecent;
	newEntry.exerciseType = exerciseTypeRecent;
	newEntry.workoutTime = workoutTimeRecent;

	user.fitnessData.push_back(newEntry);

	cout << "Data Added!" << endl;
}

void printRecentData(User& user) //(Option 2)
{
	if (user.fitnessData.size() > 0) {
	FitnessRecord userDataRecent = user.fitnessData.back();
		cout << "\t" << user.name << endl
			<< user.gender << ", " << user.age << ", " << user.height << "m" << endl;
		cout << "Weight: " << userDataRecent.weight << " kg, BMI: " 
			<< userDataRecent.weight / (user.height * user.height) << "kg/m^2" << endl;
		cout << "Exercise: " << userDataRecent.exerciseType 
			<< "(" << userDataRecent.workoutTime << " mins)" << endl;
	}
	else {
		cout << "There is no fitness data to print." << endl;
	}
}

void printHistoryData(User user) // (Option 3)
{
	int size = user.fitnessData.size();
	if (size > 0) {
		cout << "\t" << user.name << endl
			<< user.gender << ", " << user.age << ", " << user.height << "m" << endl;
		cout << "Fitness Data (Most recent to oldest): " << endl;
		int totalTime = 0;
		for (int i = (size-1); i >= 0; i--) {
			FitnessRecord currData = user.fitnessData.at(i);
			cout << "Weight: " << currData.weight 
				<< " kg, BMI: " << currData.weight / (user.height * user.height) 
				<< "kg/m^2" << endl;
			cout << "Exercise: " << currData.exerciseType 
				<< "(" << currData.workoutTime << " mins)" << endl;
			totalTime += currData.workoutTime;
		}

		double diffenceBMI; 
		// this is to keep the number positive depending on if the number is a increase in bmi or decrease
		if ((calculateBMI(user.fitnessData.back().weight, user.height) - calculateBMI(user.fitnessData.front().weight, user.height)) > 0) {
			diffenceBMI = calculateBMI(user.fitnessData.back().weight, user.height) - calculateBMI(user.fitnessData.front().weight, user.height);
			cout << "Change in BMI from oldest entry to most recent entry: "
				<< diffenceBMI << " kg/m^2 (Increase)" << endl;
		}
		else {
			diffenceBMI = calculateBMI(user.fitnessData.front().weight, user.height) - calculateBMI(user.fitnessData.back().weight, user.height);
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
	int input = 0;


	//Vector of Fitness Data
	vector<FitnessRecord>* userData;

	//Main Start!!
	User newUser;
	getBasicInfo(newUser);
	
	cout << "\nWelcome, " << newUser.name << "!" << endl;
	
	do {
		printMenu();
		input = getOption();
		switch (input) {
		case 1:
			inputData(newUser);
			break;
		case 2:
			printRecentData(newUser);
			break;
		case 3:
			printHistoryData(newUser);
			break;
		case 4:
			cout << "Ending program, Goodbye!" << endl;
			break;
		}
		cout << '\n' << endl;
	} while (input != OPTION_LIM);

	return 0;
}
