#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class stadiumData {
private:
    string matchName;
    string leftPlayer;
    string rightPlayer;
    string timeSlot;
    int ticketsBooked;
    int ticketPrice;
public:
    stadiumData(string matchName, string leftPlayer, string rightPlayer, string timeSlot, int ticketsBooked, int ticketPrice) {
        this->matchName = matchName;
        this->leftPlayer = leftPlayer;
        this->rightPlayer = rightPlayer;
        this->timeSlot = timeSlot;
        this->ticketsBooked = ticketsBooked;
        this->ticketPrice = ticketPrice;
    }

    void setStadiumInputs() {
        cin >> matchName;
        cin >> leftPlayer;
        cin >> rightPlayer;
        cin >> timeSlot;
        cin >> ticketsBooked;
        cin >> ticketPrice;
    }

    char highestTicketSales(int firstMatchTicketsSold, int secondMatchTicketsSold, int thirdMatchTicketsSold) {
        int highestMatch = max(firstMatchTicketsSold, secondMatchTicketsSold, thirdMatchTicketsSold);
        char highestName = ' ';
        if (highestMatch == firstMatchTicketsSold) {
            highestName = '1';
            return highestName;
        }
        else if (highestMatch == secondMatchTicketsSold) {
            highestName = '2';
            return highestName;
        }
        else {
            highestName = '3';
            return highestName;
        }
    }

    void stadiumOutputs() {
        cout << matchName << "has sold " << ticketsBooked << " tickets\n";

    }
};

int main() {
    string matchName;
    string leftPlayer;
    string rightPlayer;
    string timeSlot;
    int ticketsBooked = 0;
    int ticketPrice = 0;
    char highestName = ' ';
    int maxTicketsBooked = 0;

    stadiumData match1("Match 1", "Jim", "Tony", "Afternoon", 245, 40);
    stadiumData match2("Match 2", "Bob", "Ethan", "Morning", 129, 60);
    stadiumData match3("Match 3", "James", "Sam", "Evening", 499, 80);
    


    cout << "Match " << highestName << " sold the most tickets with " << "\n";
    cout << "Player on the left " << leftPlayer << "\n";
    cout << "Player on the right " << rightPlayer << "\n";
    cout << "Playing Time: " << timeSlot << "\n";
    cout << "";
}