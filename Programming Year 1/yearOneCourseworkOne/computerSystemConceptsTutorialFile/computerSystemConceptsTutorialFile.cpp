// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    short a = 1;
    long int b = 2;
    bool flag = true;
    float f1 = 10.5; //Search the Internet for definitions of IEEE-754 
    double f2 = 5.5; //Search the Internet for definitions of IEEE-754 
    int x = 10;
    int y = 11;
    int z = 12;
    int values[4] = { 1,2,3,4 };
    int valuesElements = sizeof(values) / sizeof(int);

    string strBin;
    int byteCount;
    const int shortIntBytes = sizeof(a);
    const int longIntBytes = sizeof(b);
    const int floatBytes = sizeof(f1);
    const int intBytes = sizeof(x);
    const int boolBytes = sizeof(flag);
    const int doubleBytes = sizeof(f2);

    const int shortIntBits = shortIntBytes * 8;
    const int longIntBits = longIntBytes * 8;
    const int intBits = intBytes * 8;
    const int boolBits = boolBytes * 8;
    const int floatBits = floatBytes * 8;
    const int doubleBits = doubleBytes * 8;

    cout << "Variable a (short) is " << shortIntBytes << " bytes or " << shortIntBits << " bits.\n";
    cout << "Variable a is located at " << &a << "\n";
    cout << "Variable a contains " << a << "\n";
    strBin = std::bitset<shortIntBits>(a).to_string();
    cout << strBin << "\n\n";

    cout << "Variable b (long int) is " << longIntBytes << " bytes or " << longIntBits << " bits.\n";
    cout << "Variable b is located at " << &b << "\n";
    cout << "Variable b contains " << b << "\n";
    strBin = std::bitset<longIntBits>(b).to_string();
    cout << strBin << "\n\n";

    cout << "Variable flag (bool) is " << boolBytes << " byte(s) or " << boolBits << " bits.\n";
    cout << "Variable flag is located at " << &flag << "\n";
    cout << "Variable flag contains " << flag << "\n";
    strBin = std::bitset<boolBits>(flag).to_string();
    cout << strBin << "\n\n";

    cout << "Variable f1 (float) is " << floatBytes << " bytes or " << floatBits << " bits.\n";
    cout << "Variable f1 is located at " << &f1 << "\n";
    cout << "Variable f1 contains " << f1 << "\n";
    strBin = std::bitset<floatBits>(f1).to_string(); //bitset only works on integers i.e. 10 here
    cout << strBin << "\n\n";
    unsigned long long bits;  //unsigned long long is a c++ data type
    bits = *reinterpret_cast<unsigned long long*>(&f1);
    cout << "bits contains " << bits << "\n";
    strBin = std::bitset<sizeof(bits) * 8>(bits).to_string();
    cout << strBin << "\n\n";

    uint64_t u;
    memcpy(&u, &f1, sizeof(f1));
    std::cout << std::hex << u << "\n\n";


    cout << "Variable f2 (double) is " << doubleBytes << " bytes or " << doubleBits << " bits.\n";
    cout << "Variable f2 is located at " << &f2 << "\n";
    cout << "Variable f2 contains " << f2 << "\n";
    strBin = std::bitset<doubleBits>(f2).to_string(); //bitset only works on integers i.e. 5 here
    cout << strBin << "\n\n";

    cout << "Variable x (int) is " << intBytes << " bytes or " << intBits << " bits.\n";
    cout << "Variable x is located at " << &x << "\n";
    cout << "Variable x contains " << x << "\n";
    strBin = std::bitset<intBits>(x).to_string();
    cout << strBin << "\n\n";

    cout << "Variable y is " << intBytes << " bytes or " << intBits << " bits.\n";
    cout << "Variable y is located at " << &y << "\n";
    cout << "Variable y contains " << y << "\n";
    strBin = std::bitset<intBits>(y).to_string();
    cout << strBin << "\n\n";

    cout << "Variable z is " << intBytes << " bytes or " << intBits << " bits.\n";
    cout << "Variable z is located at " << &z << "\n";
    cout << "Variable z contains " << z << "\n";
    strBin = std::bitset<intBits>(z).to_string();
    cout << strBin << "\n\n";

    byteCount = sizeof(values);
    cout << "Variable values is " << byteCount << " bytes or " << byteCount * 8 << " bits.\n";
    cout << "Variable values is located at " << &values << "\n";
    cout << "The int array values contains " << valuesElements << " elements\n";
    cout << "Each element in the int array values is " << byteCount << " bytes or " << intBits << " bits.\n\n";
    for (int index = 0; index < valuesElements; index++)
    {
        cout << "Variable values[" << index << "] is " << intBytes << " bytes or " << intBits << " bits.\n";
        cout << "Variable values[" << index << "] is located at " << &values[index] << "\n";
        cout << "Variable values[" << index << "] contains " << values[index] << "\n";
        strBin = std::bitset<intBits>(values[index]).to_string();
        cout << strBin << "\n\n";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file