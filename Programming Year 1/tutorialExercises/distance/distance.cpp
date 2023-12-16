// distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    //initialised variables
    int distance = 0;
    int speed = 0;
    int time = 0;
    //inputs
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    cout << "\n";
    cout << "How many hours has it travelled? \n";
    cin >> time;
    //format table title for output
    cout << "Hour  Miles Travelled\n" << "--------------------------\n";
    //for loop, uses the total of time to tick up i, then prints it alongside distance which the speed is added to every time i ticks up by 1
    for (int i = 1; i <= time; i++) {
        distance += speed;

        cout << i << "     " << distance << "\n";
    }
}
