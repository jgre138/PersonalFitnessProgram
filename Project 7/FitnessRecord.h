#pragma once
#include "Date.h"
#include <string>
class FitnessRecord
{
private:
	double weight;
	std::string exerciseType;
	int workoutTime;
	Date date;
public:
	FitnessRecord();
	FitnessRecord(double weight, std::string exerciseType, int workoutTime, Date date);
	void setWeight(double weight);
	void setExerciseType(std::string exerciseType);
	void setWorkoutTime(int workoutTime);
	void setDate(Date date);
	double getWeight();
	std::string getExerciseType();
	int getWorkoutTime();
	Date getDate();
	std:: string print(double height);
};

