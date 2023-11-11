#include <iostream>
#include <cmath>
using namespace std;



int addition(int input1 = 0, int input2 = 0) {
    cin >> input1;
    cin >> input2;
    return input1 + input2;
}

int main()
{
    cout << addition();
}
