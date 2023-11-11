#include <iostream>
using namespace std;
double toPounds(double ton) {
    return ton * 2240;
}

double toKilograms(double ton) {
    return ton * 1016.05;
}

int main()
{
    cout << "|-----------------------------------------------|\n";
    cout << "|Tons           |Pounds         |Kilograms      |\n";
    cout << "|-----------------------------------------------|\n";
    for (int ton = 2; ton <= 20; ton += 2) {
        double pounds = toPounds(ton);
        double kilos = toKilograms(ton);

        cout << left << "|" << ton << "\t\t|" << pounds << "\t\t|" << kilos << "  \t|\n";
    }
    cout << "|-----------------------------------------------|\n";
}