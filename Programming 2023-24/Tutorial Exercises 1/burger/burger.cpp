// burger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double kids = 2.50;
    double ham = 3.50;
    double cheese = 4.20;
    double cheesenbacon = 5.00;
    double kidsAmount;
    double hamAmount;
    double cheeseAmount;
    double cheesenbaconAmount;

    cin >> kidsAmount;
    cin >> hamAmount;
    cin >> cheeseAmount;
    cin >> cheesenbaconAmount;

    double kidsTotal = kidsAmount * kids;
    double hamTotal = hamAmount * ham;
    double cheeseTotal = cheeseAmount * cheese;
    double cheesenbaconTotal = cheesenbaconAmount * cheesenbacon;

    double total = kidsTotal + hamTotal + cheeseTotal + cheesenbaconTotal;
    total = round(total * 100.00) / 100.00;
    cout << "Total sales for the day $" << fixed << setprecision(2) << total;
}
