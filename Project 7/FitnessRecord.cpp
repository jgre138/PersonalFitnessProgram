#include "FitnessRecord.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

FitnessRecord::FitnessRecord() {
	setWeight(0.0);
	setExerciseType("");
	setWorkoutTime(0);
	setDate(Date());
}
FitnessRecord::FitnessRecord(double weight, std::string exerciseType, int workoutTime, Date date) {
	setWeight(weight);
	setExerciseType(exerciseType);
	setWorkoutTime(workoutTime);
	setDate(date);
}
void FitnessRecord::setWeight(double weight) {
	this->weight = weight;
}
void FitnessRecord::setExerciseType(std::string exerciseType) {
	this->exerciseType = exerciseType;
}
void FitnessRecord::setWorkoutTime(int workoutTime) {
	this->workoutTime = workoutTime;
}
void FitnessRecord::setDate(Date date) {
	this->date = date;
}
double FitnessRecord::getWeight() {
	return weight;
}
string FitnessRecord::getExerciseType() {
	return exerciseType;
}
int FitnessRecord::getWorkoutTime() {
	return workoutTime;
}
Date FitnessRecord::getDate() {
	return date;
}
string FitnessRecord::print(double height) { 
	double bmi = weight / (height * height);
	stringstream format;
	format << fixed << setprecision(2);
	format << "Date: " << date.toString() << "\n" <<
		weight << " kg, BMI: " << bmi << "kg/m^2\n"
		"Exercise: " << exerciseType + "(" << workoutTime << " minutes)\n";
	string str = format.str();
	return str;
}