// monthlyincome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{   //a variable to store the basic pay of the employee, which in this exercise is noted as $5000, so I set it as this during initialisation
    double basicPay = 5000;
    //variables serving no other purpose than to add clarity in futher calcualtions regarding pay
    double medicalAllowancePercent = 0.125;
    double bonusPercent = 0.55;
    //calculations for medical allowance, bonus and the total income when all are added together
    double medicalAllowance = basicPay * medicalAllowancePercent;
    double bonus = basicPay * bonusPercent;
    double totalIncome = basicPay + medicalAllowance + bonus;
    //print outs following the exercise outline precisely
    std::cout << "Basic Pay is $" << basicPay << "\n";
    std::cout << "Bonus is $" << bonus << "\n";
    std::cout << "Medical Allowance is $" << medicalAllowance << "\n";
    std::cout << "Total is $" << totalIncome << "\n";

}
