#include <iostream>
#include <iomanip>
using namespace std;

class Time24 {
    //initialised variables for the hours, minutes and seconds
    int hours = 00;
    int minutes = 00;
    int seconds = 00;
public:
    /*
    *default constructor takes in the hours, minutes and seconds; sets limits on what can be entered,
    *if it is over or under the limit, everything is set to 0, otherwise it continues, pointing this variable to the class initialised variable
    */
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
    //setw and setfill as a char ensure that when numbers are single digit, it shows as e.g 02:07 instead of 2:7. char was chosen to make sure they do not interact with the integers
    void twentyFourHrFormat() {
        cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
    }
    // divides hours by 12 to recieve the 12 hour formot, then sets 0 to 12 with an if statement as a simple way of overriding that issue
    void twelveHrFormat() {
        int twelveHr = hours % 12;
        string AMorPM = "";
        if (twelveHr == 0) {
            twelveHr = 12;
        }
        //ternery replaces the need for another if else statement here, offering readability and efficiency
        cout << setw(2) << setfill('0') << twelveHr << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << (hours < 12 ? "AM" : "PM");
    }
    //message as per the exercise specs
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
    //variables initialised, messages printed to ask for inputs, time initialised and then couts as per specification
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