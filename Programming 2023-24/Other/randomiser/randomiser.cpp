// randomiser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    int heroChoice = rand() % 124;
    cout << heroChoice;
}