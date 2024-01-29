// triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	double s = (a + b + c) / 2;
	double calculate = s * (s - a) * (s - b) * (s - c);
	double area = sqrt(calculate);
	area = round(area * 100.0) / 100.0;

	if (area <= 180) {
		cout << "Triangle is valid\n";
		cout << "area is " << area << "\n";
	}
	else {
		cout << "This is not a valid triangle\n";
	}
}
