// weighttable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
//function that uses the conversion multiplication to turn tonnes to pounds
double toPounds(double ton) {
    return ton * 2240;
}
//function that uses the conversion multiplication to turn tonnes to kilograms
double toKilogram(double ton) {
    return ton * 1016.05;
}
int main()
{
    //four couts (3 above for loop, 1 below) build parts of the weight table manually to avoid the forloop print system for each row
    cout << "|--------------------------------|\n";
    cout << "|Tons      |Pounds    |Kilograms |\n";
    cout << "|--------------------------------|\n";
    //for loop prints each row of the table
    for (int ton = 2; ton < 21; ton += 2) {
        int pounds = toPounds(ton);
        double kilograms = toKilogram(ton);
        
        cout << left << "|" << setw(10) << ton  << "|" << setw(10) << pounds  << "|" << setw(10) << kilograms <<"|\n";
    }
    cout << "|--------------------------------|";
}


