#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//class containing a base and height then uses the default constructor to place them into the public code, then uses the formulas for finding the area and perimeter of a triangle in the relative functions
class IsoscelesTriangle {
private:
    double base;
    double height;
public:
    IsoscelesTriangle(double base, double height) {
        this->base = base;
        this->height = height;
    }
    //area = 1/2 × base × height
    double area() {
        double area = (base * height) / 2;
        return area;
    }
    //Perimeter = 2 * base + sqrt((2 * base)² + 4 * (height)²)
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