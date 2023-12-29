#include <iostream>
using namespace std;

class Circle {
private:
	double centerX;
	double centerY;
	double radius;
	double center;
public:
	void setCenter(double x, double y) {
		centerX = x;
		centerY = y;
	}
	void setRadius(double r) {
		radius = r;
	}
	double getCenter() {
		return center;
	}
	double getRadius() {
		return radius;
	}
};

int main() {
	Circle circ;
	circ.setRadius(2);
	cout << circ.getRadius();
	
}