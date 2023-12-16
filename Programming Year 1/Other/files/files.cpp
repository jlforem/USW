// files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int studentNumber, studentFees;
    char studentName[20];
    fstream file("studentDetails.txt", ios::app);
    /*cout << "Enter the student n0\n";
    cin >> studentNumber;
    cout << "Enter the student name\n";
    cin >> studentName;
    cout << "Enter the students fees due\n";
    cin >> studentFees;
    file << studentNumber << "\t" << studentName << "\t" << studentFees << "\n";*/
    file.open("studentDetails.txt");
    while (file) {
        file >> studentNumber >> studentName >> studentFees;
        cout << "The details from the files are: \n";
        cout << studentNumber << "\t" << studentName << "\t" << studentFees << "\n";
    }
    file.close();
}

