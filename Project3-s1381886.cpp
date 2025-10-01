/*
	Project 3 by Jennifer Greene

	This is a personal fitness application that records 
	your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.
	The user can log the exercise they did for the day 
	and the duration of the workout.
	Update (9/17) : Added verification for most of the 
	inputs giving an error message. Updated some of the 
	print statements to look nicer
	Update (9/22) : Made methods to simplify code. Added 
	switch case in a do while for users to choose what
	they would like to do. Added spacing to printed text
	to make it look nicer.
	Update (9/25) : Made getNum() generic so that it can
	work with any number

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template <typename D>
D getNum()
{
	D value;
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

void displayData(string name, char gender, int age, double height, double weight, 
	string exerciseType, int workoutTime)
{
	cout << "\t" << name << endl
		<< gender << ", " << age << ", " << height << " m" << endl;
	cout << "Weight: " << weight << " kg, BMI: " << weight / (height * height) << "kg/m^2" << endl;
	cout << "Exercise: " << exerciseType << "(" << workoutTime << " mins)" << endl;

}


int main() 
{
	string name = "n/a", exerciseType = "n/a";
	char gender = 'n';
	int age = 0, workoutTime = 0, input = 0;
	double height = 0, weight = 0;


	cout << "Please provide your name, gender(f - female /m - male /o - other), age, and height(m)"
		<< endl 
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
	age = getNum<int>();

	cout << "Height: ";
	height = getNum<double>();

	//End of unchanging data
	
	cout << "\nWelcome, " << name << "!" << endl;
	
	
	do {
		cout << "What would you like to do?\n"
			<< "1 - Add data \n" << "2 - Recent Data \n" << "3- Exit Program" << endl;
		cout << "Choice: ";
		input = getNum<int>();
		switch (input) {
		case 1:
			
			cout << "\n Please enter your weight(kg) from today." << endl;
			cout << "Weight: ";
			weight = getNum<double>();

			cout << "Please provide the exercise type and elapsed workout time(minutes): " << endl
				<< "Exercise type: ";
			cin.ignore();
			getline(cin, exerciseType);

			cout << "Duration: ";
			workoutTime = getNum<int>();

			cout << "Data Added!" << endl;
			break;
		case 2:
			if (weight != 0) { 
				// only used weight since the case has validation requiring a value over 0 for int
				displayData(name, gender, age, height, weight, exerciseType, workoutTime);
				break;
			}
			else {
				cout << "There is no fitness data to print." << endl;
				break;
			}
			break;
		case 3:
			cout << "Ending program, Goodbye!" << endl;
			break;
		default:
			cout << "The selected option is invalid, please try again: ";
			input = getNum<int>();
		}
		cout << "\n";
	} while (input != 3);

	return 0;
}

