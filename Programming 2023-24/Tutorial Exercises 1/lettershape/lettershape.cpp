// lettershape.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a[7] = { " ", " ", " ", " ", " ", " ", "A" };
	string b[7] = { " ", " ", " ", " ", " ", "B", "B" };
	string c[7] = { " ", " ", " ", " ", "C", "C", "C" };
	string d[7] = { " ", " ", " ", "D", "D", "D", "D" };
	string e[7] = { " ", " ", "E", "E", "E", "E", "E" };
	string f[7] = { " ", "F", "F", "F", "F", "F", "F" };
	string g[7] = { "G", "G", "G", "G", "G", "G", "G" };
	for (int i = 0;  i < 7; i++) {
		cout << a[i];
	}
	cout << "\n";
	for (int i = 0; i < 7; i++) {
		cout << b[i];
	}
	cout << "\n";
	for (int i = 0; i < 7; i++) {
		cout << c[i];
	}
	cout << "\n";
	for (int i = 0; i < 7; i++) {
		cout << d[i];
	}
	cout << "\n";
	for (int i = 0; i < 7; i++) {
		cout << e[i];
	}
	cout << "\n";
	for (int i = 0; i < 7; i++) {
		cout << f[i];
	}
	cout << "\n";
	for (int i = 0; i < 7; i++) {
		cout << g[i];
	}
}