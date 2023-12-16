// mobileplan.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*A mobile phone company offers 3 plans:
Plan A : For $29.99 a month, 450 minutes are included and 1GB of data.Additional usage costs $0.45 a minute and £2 per Gb

Plan B : For $39.99 a month, 900 minutes are included and 3Gb of data.Additional usage costs $0.40 a minute and £1.50 per Gb

Plan C : For $59.99 a month, Unlimited minutes and data.

Write a program that calculates the customer’s monthly bill.IT should input customer name, which package the customer has purchased, and how many minutes and data were used.IT should then create a bill that includes the input information and the total amount to pay.It should also display how much money package A customers would save if they purchased package B or C, and how much money package B customers would save if they purchased package C.If there would be no savings, no message should be printed.
Output should look like :
Customers Bill
Plan < value >
Total cost for this month is : $< value >
You would get a better deal on plan < value > : $ < value >
*/

#include <iostream>
using namespace std;
int main()
{
    const double planAcost = 29.99;
    const double planAmins = 450;
    const double planAdata = 1000;
    const double planAadditionalMinsCost = 0.45;
    const double planAadditionalDataCost = 2.00;

    const double planBcost = 39.99;
    const double planBmins = 900.00;
    const double planBdata = 3000;
    const double planBadditionalMinsCost = 0.40;
    const double planBadditionalDataCost = 1.50;

    const double planCcost = 59.99;

    string name = "";
    char package = 'A';
    double minutes = 0;
    double data = 0;
    double additionalMinutesCost = 0;
    double additionalDataCost = 0;
    double totalCostA = 29.99;
    double totalCostB = 39.99;
    double totalCostC = 59.99;
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
            return additionalMinutesCost;
        }
        else {
            additionalMinutesCost = 0;
            return additionalMinutesCost;
        }
        if (data > 1000) {
            additionalDataCost = (data - planAdata) * planAadditionalDataCost;
            return additionalDataCost;
        }
        else {
            additionalDataCost = 0;
            return additionalDataCost;
        }

        totalCostA = additionalDataCost + additionalMinutesCost + planAcost;

        cout << "Customers Bill\n";
        cout << "Plan " << package;
        cout << "Total cost for this month is: $" << totalCostA;
        
    }
            break;
    case 'B': {
        if (minutes > 450) {
            additionalMinutesCost = (minutes - planBmins) * planBadditionalMinsCost;
            return additionalMinutesCost;
        }
        else {
            additionalMinutesCost = 0;
            return additionalMinutesCost;
        }
        if (data > 1000) {
            additionalDataCost = (data - planBdata) * planBadditionalDataCost;
            return additionalDataCost;
        }
        else {
            additionalDataCost = 0;
            return additionalDataCost;
        }

        cout << "Customers Bill\n";
        cout << "Plan " << package;
        cout << "Total cost for this month is: $" << totalCost;
    }
            break;
    case 'C': {
        cout << "Customers Bill\n";
        cout << "Plan " << package;
        cout << "Total cost for this month is: $" << totalCost;
    }
    default: {
        cout << "Please enter a correct package\n";
    }
           exit;
    }
    if (totalCostA < totalCostB && totalCostA < totalCostC) {
        cout << "You would get a better deal on plan A: $" << totalCostA;
    }
    else if (totalCostB < totalCostA && totalCostB < totalCostC) {
        cout << "You would get a better deal on plan A: $" << totalCostB;
    }
    else if (totalCostC < totalCostA && totalCostC < totalCostB) {
        cout << "You would get a better deal on plan A: $" << totalCostC;
    }
    else {
        return 0;
    }
}
