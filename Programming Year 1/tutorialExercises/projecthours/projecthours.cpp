// projecthours.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int bobDays;
    int jennyDays;
    cin >> bobDays;
    cin >> jennyDays;
    int bobHours = bobDays * 4;
    int bobMinutes = bobDays * 30;
    int jennyHours = jennyDays * 3;
    int jennyMinutes = jennyDays * 15;

    while (bobMinutes >= 60) {
        bobHours = bobHours + 1;
        bobMinutes = bobMinutes - 60;
    }
    while (jennyMinutes >= 60) {
        jennyHours = jennyHours + 1;
        jennyMinutes = jennyMinutes - 60;
    }

    cout << "Bob worked a total of " << bobHours << " hours and " << bobMinutes << " minutes on the project\n";
    cout << "Jenny worked a total of " << jennyHours << " hours and " << jennyMinutes << " minutes on the project\n";
}
