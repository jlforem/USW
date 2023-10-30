// marks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    float average = (a + b + c) / 3;
    cout << "Average mark is " << fixed << setprecision(2) << average << "%\n";
    
}
