#include <iostream>
using namespace std;

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
    int year;
    int holidays;
    int sundays = 52;
    int isleap;
    int workingdays;
    cout << "Please enter the year in the format XXXX: \n";
    cin >> year;
    cout << "How many holidays are in this year?: \n";
    cin >> holidays;

    isLeap(year);
    if (isLeap(year) == true) {
        isleap = 366;
    }
    else {
        isleap = 365;
    }

    workingdays = isleap - holidays - sundays;

    cout << "Total days in the year " << year << ": " << isleap << "\n";
    cout << "There are " << holidays << " holidays\n";
    cout << "There are 52 Sundays\n";
    cout << "there are " << workingdays << " working days\n";
}