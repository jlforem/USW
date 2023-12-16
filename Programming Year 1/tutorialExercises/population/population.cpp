// population.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double population = 7700000000;
    double tenRise = population * 0.10 + population;
    double fifteenRise = population * 0.15 + population;
    double twentyRise = population * 0.20 + population;

    cout << "The world population is " << 7700000000 << "\n";
    cout << "if the world population rose by 10% it would be " << fixed << setprecision(0) << tenRise << "\n";
    cout << "if the world population rose by 15% it would be " << fifteenRise << "\n";
    cout << "if the world population rose by 20% it would be " << twentyRise << "\n";
}
