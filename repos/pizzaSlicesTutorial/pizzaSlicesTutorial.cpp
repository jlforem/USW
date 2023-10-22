// Programming Challenge, Pizza Slices 

//  This program calculates the number of slices in a pizza.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


/*
(A) Ask the user for the diameter of the pizza in inches.
(B) Divide the diameter by 2 to get the radius.
(C) Calculate the number of slices that may be taken from a pizza of that size if each slice has an area of 14.125 square inches.
(D) Display a message telling the number of slices.
*/
int main()
{
    // Declare all the variables you will be using within this program
    float diameter = 0;
    cout << "Please enter the diameter of the pizza in inches: ";
    cin >> diameter;
    double radius = diameter / 2.0;
    cout << radius;
    double areaForC = 14.125;
    const double pi = 3.14;

    // Expand the required Logic to solve this problem
    double totalArea = pi * pow(radius, 2);
    cout << totalArea;
    double slices = totalArea / 14.125;

    // Display results to the nearest whole number

    cout << "Cut this pizza into " << round(slices) << " slices.";
}

/* SAMPLE RUN RESULTS

Enter the pizza diameter (in inches): 14
Cut this pizza into 11 slices.
*/
