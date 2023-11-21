#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class IsoscelesTriangle {
private:
    double base;
    double height;
public:
    IsoscelesTriangle(double base, double height) {
        this->base = base;
        this->height = height;
    }
    double area() {
        double area = (base * height) / 2;
        return area;
    }
    double perimeter() {
        double perimeter = base + sqrt((base * base) + 4 * (height * height));
        return perimeter;
    }
};

int main()
{
    double base;
    double height;
    cout << "Enter base: \n";
    cin >> base;
    cout << "Enter height: \n";
    cin >> height;

    IsoscelesTriangle isosTriangle(base, height);

    cout << "Area " << isosTriangle.area() << "\n";
    cout << "Perimeter " << isosTriangle.perimeter() << "\n";
}