// weighttable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double toPounds(double ton) {
    return ton * 2240;
}

double toKilogram(double ton) {
    return ton * 1016.05;
}

int main()
{

    for (double ton = 2; ton < 21; ton += 2) {
        double pounds = toPounds(ton);
        double kilograms = toKilogram(ton);
        
        cout << "|" << ton << "\t|" << pounds << "\t|" << kilograms << "  |\n";
    }
}


