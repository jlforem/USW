// whatDoYouWantForBreakfast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
int main()
{
    std::string breakfast = " ";
    std::cout << "What do you want for breakfast?\n";
    std::cin >> breakfast;
    std::cout << "You are eating " << breakfast << " for breakfast.\n";
}

