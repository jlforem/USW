#include <iostream>
using namespace std;

class Moon {
private:
	double earthWeight;
	double moonWeight;
public:
	void setMoonWeight(double ew) {
		earthWeight = ew;
		moonWeight = earthWeight / 6;
	}
	double getMoonWeight() {
		return moonWeight;
	}
};
int main()
{
	double earth;

	cout << "Whats your weight?";
	cin >> earth;
	Moon lunar;
	lunar.setMoonWeight(earth);
	cout << "On the moon you would weigh " << lunar.getMoonWeight() << "\n";
	return 0;
}