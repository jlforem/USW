// tutorialOneWeekThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<iomanip>

int main()
{
//Q1. write a cin statement that reads in a one word description
	std::string description = " ";
	//std::cin >> description;
	
//Q1 multiple words
	std::string descriptiontwo = " ";
	//getline(std::cin, descriptiontwo);
	//std::cout << descriptiontwo;

//Q2 definition statement for a c string large enough to hold the resembling strings

	char largeEnough[] = "Billy Bob's Pizza";
	//std::cout << largeEnough;

//Q3 assume the c string name is defined as char name [25]
	//Using a stream manipulator, write a cin statement that will read a string into name but that will read no more characters than name can hold
	char name[25];
	std::cin >> name;
	std::cout << std::setw(25) << "Your name is: " << name <<  "\n";
	const float pi = 3.14;

//Q4 
}

