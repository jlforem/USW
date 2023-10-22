// numbers to words

#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number between 11 and 20\n";
    cin >> number;
    if ((number >= 11) && (number <= 20)) {
        //valid input
        cout << "The number \"" << number << "\" in words is: ";
        switch (number) {
        case 11: cout << "Eleven\n";
            break;
        case 12: cout << "Twelve\n";
            break;
        case 13: cout << "Thirteen\n";
            break;
        case 14: cout << "Fourteen\n";
            break;
        case 15: cout << "Fifteen\n";
            break;
        case 16: cout << "Sixteen\n";
            break;
        case 17: cout << "Seventeen\n";
            break;
        case 18: cout << "Eighteen\n";
            break;
        case 19: cout << "Nineteen\n";
            break;
        case 20: cout << "Twenty\n";
            break;
        }
    }
    else {
        //invalid input
        cout << "The number must be between eleven and twenty.\n";
    }
}

