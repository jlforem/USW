#include <iostream>
using namespace std;

struct TwoVals
{
	int a = 5;
	int b = 10;
};

int main()
{
	TwoVals v;
	cout << v.a << " " << v.b;
	return 0;
}