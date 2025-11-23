#pragma once
#include <string>
#include <iostream>

class Helper
{
public:
	template<typename D>
	static D getInput() {
		D value = 0;
		std::cin >> value;
		while (std::cin.fail() || value <= 0)
		{
			std::cout << "Invalid number, please try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> value;
		}
		return value;
	}
	template <>
	static char getInput() {
		char value;
		std::cin >> value;
		while (value != 'f' && value != 'm' && value != 'o'
			&& value != 'F' && value != 'M' && value != 'O') // allows for uppercase and lowercase
		{
			std::cout << "Invalid gender, please try again: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> value;
		}
		return value;
	}
	template <>
	static std::string getInput() { //Prevents a name with integers in them
		std::string data;
		while (true) {
			std::getline(std::cin, data);
			bool hasDigit = false;
			for (int index = 0; index < data.length(); index++) {
				if (std::isdigit(data.at(index))) {
					hasDigit = true;
					break;
				}
			}
			if (!hasDigit) {
				return data;   // valid input
			}
			std::cout << "Invalid input (no digits allowed). Try again: ";
		}
	}
	template<typename T>
	static T* resizeArray(T* arr, int oldSize) {
		T* newArr = new T[oldSize * 2];
		for (int i = 0; i < oldSize; ++i) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		return newArr;
	}
};

