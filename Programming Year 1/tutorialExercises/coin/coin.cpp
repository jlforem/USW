// coin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    //random number of 0 and 1 to indicate heads(1) or tails(0)
	srand(time(NULL));
	int toss = rand() % 2;
	cout << toss << "\n";

	char letter = 'A';
	cout << "Please enter Head or Tails in terms 'H' or 'T':\n";
	cin >> letter;
	switch(letter) {
	case 'H':
		if (toss == 1) {
			cout << "You win\n";
		}
		else {
			cout << "You lose\n";
		}
		break;
	case 'T':
		if (toss == 0) {
			cout << "You win\n";
		}
		else {
			cout << "You lose\n";
		}
		break;
	}
}
