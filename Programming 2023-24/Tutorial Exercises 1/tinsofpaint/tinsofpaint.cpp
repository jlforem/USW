// tinsofpaint.cpp : This program will report how many tins of paint are required to cover a fence that is 6 feet high and 100 feet long, each tin covers 340 square feet
//

#include <iostream>
#include<cmath>

int main()
{
    //initialisation of necesscery variables including those purely for readability of the calculations
    double paintCoverage = 340;
    double fenceHeight = 6;
    double fenceLength = 100;
    double fenceArea = 0;
    double tinsNeeded = 0;
    //calculations for the area of the fence and the tins needed to cover such an area
    fenceArea = fenceHeight * fenceLength;
    tinsNeeded = fenceArea / paintCoverage;
    //output of these calculations as per the exercise outline
    std::cout << "For your fence which is " << fenceArea << "sqft you will need " << round(tinsNeeded) << " tins of paint";
}

