// budget.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double monthlyRent = 0;
    double monthlyInternet = 0;
    double monthlyGas = 0;
    double monthlyElectricity = 0;
    double monthlyWater = 0;

    cin >> monthlyRent;
    cin >> monthlyInternet;
    cin >> monthlyGas;
    cin >> monthlyElectricity;
    cin >> monthlyWater;

    double yearlyRent = monthlyRent * 12;
    double yearlyInternet = monthlyInternet * 12;
    double yearlyGas = monthlyGas * 12;
    double yearlyElectricity = monthlyElectricity * 12;
    double yearlyWater = monthlyWater * 12;

    cout << "Here is your cost breakdown\n";
    cout << "Monthly Rent: $" << fixed << setprecision(2) << monthlyRent << "\n";
    cout << "Yearly Rent: $" << yearlyRent << "\n";
    cout << "Monthly Internet: $" << monthlyInternet << "\n";
    cout << "Yearly Internet: $" << yearlyInternet << "\n";
    cout << "Monthly Gas: $" << monthlyGas << "\n";
    cout << "Yearly Gas: $" << yearlyGas << "\n";
    cout << "Monthly Electricity: $" << monthlyElectricity << "\n";
    cout << "Yearly Electricity: $" << yearlyElectricity << "\n";
    cout << "Monthly Water: $" << monthlyWater << "\n";
    cout << "Yearly Water: $" << yearlyWater << "\n";
}

