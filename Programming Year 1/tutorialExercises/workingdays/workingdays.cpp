#include <iostream>
using namespace std;
//function takes in the inputted year and uses the exercises specified parameters for a leap year in an if statement to return true if the year is a leap year
bool isLeap(int year) {
    if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    //initialised variables required for the code to work
    int year;
    int holidays;
    int sundays = 52;
    int isleap;
    int workingdays;
    //cout to ask for a year input
    cout << "Please enter the year in the format XXXX: \n";
    cin >> year;
    //cout to ask for holidays that are in the year that will be subtracted from the total to find the working days
    cout << "How many holidays are in this year?: \n";
    cin >> holidays;
    //if/else to determine the number of days in the year should isLeap be true or false
    isLeap(year);
    if (isLeap(year) == true) {
        isleap = 366;
    }
    else {
        isleap = 365;
    }
    //working days variable subtracts all non working days to get a final total then couts print as per the specification
    workingdays = isleap - holidays - sundays;

    cout << "Total days in the year " << year << ": " << isleap << "\n";
    cout << "There are " << holidays << " holidays\n";
    cout << "There are 52 Sundays\n";
    cout << "there are " << workingdays << " working days\n";
}