// moduleMarks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Module {
private:
	double moduleMark;
	Coursework coursework1, coursework2, coursework3, coursework4;
public:
	Module() {
		moduleMark = 0;
	}

	void totalModuleMark() {
		
	}
};

class Coursework {
	double mark;
	double weight;

	void courseworkInputs() {
		do {
			cout << "Enter the mark: ";
			cin >> mark;
			cout << endl;
			if (mark < 0 || mark > 100) {
				cout << "Invalid mark. Please enter a mark between 0 and 100\n";
			}
		} while (mark < 0 || mark > 100);

		do {
			cout << "Enter the weight (0.1 or 0.2): \n";
			cin >> weight;
			cout << endl;
			if (weight != 0.1 || weight != 0.2) {
				cout << "Invalid weight. Please enter 0.1 or 0.2\n";
			}
		} while (weight != 0.1 || weight != 0.2);
	}
};

class Exam {
	double mark;
	double weight;

	void examInputs() {
		do {
			cout << "Enter the mark: ";
			cin >> mark;
			cout << endl;
			if (mark < 0 || mark > 100) {
				cout << "Invalid mark. Please enter a mark between 0 and 100\n";
			}
		} while (mark < 0 || mark > 100);
	}
	void examWeighting(double courseworkTotal) {
		weight = 1 - courseworkTotal;
	}
};
	
int main() {
	Coursework coursework1, coursework2, coursework3, coursework4; Exam exam1;
}

