#include <iostream>
#include <iomanip>
using namespace std;

class Time24 {
    int hours = 00;
    int minutes = 00;
    int seconds = 00;
public:
    Time24(int hours, int minutes, int seconds) {
        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
            this->hours = 0;
            this->minutes = 0;
            this->seconds = 0;
        }
        else {
            this->hours = hours;
            this->minutes = minutes;
            this->seconds = seconds;
        }
    }
    void twentyFourHrFormat() {
        cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
    }
    void twelveHrFormat() {
        int twelveHr = hours % 12;
        string AMorPM = "";
        if (twelveHr == 0) {
            twelveHr = 12;
        }
        cout << setw(2) << setfill('0') << twelveHr << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << (hours < 12 ? "AM" : "PM");
    }
    void message() {
        if (hours >= 6 && hours <= 11) {
            cout << "Good Morning";
        }
        else if (hours >= 12 && hours <= 17) {
            cout << "Good Afternoon";
        }
        else if (hours >= 18 && hours <= 22) {
            cout << "Good Evening";
        }
        else {
            cout << "Time to sleep";
        }
    }
};


int main()
{
    int hours;
    int minutes;
    int seconds;
    cout << "Enter hours\n";
    cin >> hours;
    cout << "Enter minutes\n";
    cin >> minutes;
    cout << "Enter seconds\n";
    cin >> seconds;

    Time24 time(hours, minutes, seconds);

    cout << "12-hour format: "; time.twelveHrFormat(); cout << "\n";
    cout << "24-hour format: "; time.twentyFourHrFormat(); cout << "\n";
    time.message();
}

//00:00:00