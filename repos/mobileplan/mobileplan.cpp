// mobileplan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    double planAcost = 29.99;
    double planAmins = 450;
    double planAdata = 1000;
    double planAadditionalMinsCost = 0.45;
    double planAadditionalDataCost = 2.00;

    double planBcost = 39.99;
    double planBmins = 900.00;
    double planBdata = 3000;
    double planBadditionalMinsCost = 0.40;
    double planBadditionalDataCost = 1.50;

    double planCcost = 59.99;
    double planCmins = 0;
    double planCdata = 0;
    double planCadditionalMinsCost = 0;
    double planCadditionalDataCost = 0;

    string name = "";
    char package = 'A';
    double minutes = 0;
    double data = 0;
    double additionalMinutesCost = 0;
    string bestDeal;
    cout << "Please enter your name, your package choice and how many minutes and data were used\n";
    cin >> name;
    cin >> package;
    cin >> minutes;
    cin >> data;

    switch (package) {
    case 'A': {
        if (minutes > 450) {
            additionalMinutesCost = (minutes - planAmins) * planAadditionalMinsCost;
        }
        else {
            additionalMinutesCost = 0;
        }
    }
        break;
    case 'B': {

    }
        break;
    case 'C': {

    }
    default: {
        cout << "Please enter a correct package\n";
    }
        exit;
    }
}