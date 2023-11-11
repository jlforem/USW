// weighttable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

double toPounds(double ton) {
    return ton * 2240;
}

double toKilogram(double ton) {
    return ton * 1016.05;
}
//make use of setprecision && setwidth
int main()
{
    cout << "|--------------------------------|\n";
    cout << "|Tons      |Pounds    |Kilograms |\n";
    cout << "|--------------------------------|\n";
    for (int ton = 2; ton < 21; ton += 2) {
        int pounds = toPounds(ton);
        double kilograms = toKilogram(ton);
        
        cout << left << "|" << setw(10) << ton  << "|" << setw(10) << pounds  << "|" << setw(10) << kilograms <<"|\n";
    }
    cout << "|--------------------------------|";
}


