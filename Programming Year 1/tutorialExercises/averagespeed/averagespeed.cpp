#include <iostream>
using namespace std;
//initialise function
double averageVelocity(double, double, double, double);

int main()
{
	//variables for inputs
	double distanceXY;
	double distanceYZ;
	double timeXY;
	double timeYZ;
	//prompts and inputs for the avgVelocity output
	cout << "Please enter the distance between X and Y: ";
	cin >> distanceXY;
	cout << "PLease enter the distance between Y and Z: ";
	cin >> distanceYZ;
	cout << "PLease enter the time spent travelling between X and Y: ";
	cin >> timeXY;
	cout << "PLease enter the time spent travelling between Y and Z: ";
	cin >> timeYZ;
	//output variable for the function, allows storage of the answer so it can be formatted on the next line in between text with better readability
	double avgVelocity = averageVelocity(distanceXY, distanceYZ, timeXY, timeYZ);
	cout << "Average speed was " << avgVelocity << "Km/H";
}

double averageVelocity(double distanceXY, double distanceYZ, double timeXY, double timeYZ) {
	return (distanceXY + distanceYZ) / (timeXY + timeYZ);
}