#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Month {
private:
    int monthInput;
    int yearInput;
    string months[12] = { "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    struct tm currentTime;
    void setMonth(int, int);
public:
    Month(int monthInput, int yearInput) {
        
    }
   
    void setMonth() {
        do {
            cin >> monthInput;
            cin >> yearInput;
        } while (monthInput < 0 || monthInput > 12);
    }

   bool isLeap(int yearInput){
       if (yearInput / 400 == 0 || yearInput / 4 == 0) {
           return true;
       }
       else {
           return false;
       }
    }

   void now() {
       time_t current = time(NULL);
       localtime_s(&currentTime, &current);
   }

   void getMonth() {
       if (monthInput == 0 && yearInput == 0) {
           now();
           if (isLeap(currentTime.tm_year + 1900) == true) {
               daysInMonth[1] = 29;
           }
           cout << "The current month, " << months[currentTime.tm_mon] << " " << currentTime.tm_year + 1900 << ", has" << daysInMonth[currentTime.tm_mon] << " Days.\n";
       }
       else {
           if (isLeap(yearInput) == true) {
               daysInMonth[1] = 29;
           }
           cout << daysInMonth[monthInput - 1] << " Days\n";
       }
   }
};

int main()
{
    Month daysWithinMonth = daysWithinMonth.setMonth();
}