#include "HealthTracker.h"
using namespace std;
/*
	Project 7 by Jennifer Greene

	This is a personal fitness application that records your name, age, gender, height, and the day's weight.
	Given this information, it will calculate your BMI.The user can log the exercise they did for the day
	and the duration of the workout.
	Changelog on Github Repository: https://github.com/jgre138/PersonalFitnessProgram
*/

int main() {
	HealthTracker newUser = HealthTracker();
	newUser.exectute();
	return 0;
}