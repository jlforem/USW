#include <iostream>
using namespace std;

int grade[10] = {};

int getGrade() {
    int i = 0;

    for (int j = 0; j < 10; j++) {
        do {
            cin >> grade[j];
        } while (!(grade[j] >= 0 && grade[j] <= 100));
        if (grade[j] > 50) {
            i = i + 1;
        }
        else {
            i = i;
        }
    }
    return i;
}
int main()
{
    cout << "The scores you entered include " << getGrade() << " percentages over 50.\n";
}