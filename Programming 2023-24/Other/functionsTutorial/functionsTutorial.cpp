#include <iostream>
#include <Windows.h>
using namespace std;

int addition(int, int);
void setConsoleColour(int);

int main()
{
    
    int a = 0;
    int b = 0;
    cout << "The result is: " << addition(a, b) << "\n";
}

int addition(int a, int b) {
    setConsoleColour(4);
    cin >> a;
    setConsoleColour(10);
    cin >> b;
    setConsoleColour(1);
    cout << "The first number is: " << a << "\n";
    setConsoleColour(14);
    cout << "The second number is: " << b << "\n";
    setConsoleColour(5);
    return a + b;
}

void setConsoleColour(int colour) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}