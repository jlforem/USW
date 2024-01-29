#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/*
Inheritance and polymorphism.
Inheritance - create the base, then another area may inherit these properties.
*/

class Animal {
private:
    string name;
public:
    virtual void sound() = 0 {
        cin >> name;
        if (name == "cat") {
            cout << "meow";
        }
        else if (name == "dog") {
            cout << "bark";
        }
        else if (name == "duck") {
            cout << "quack";
        }
    }
};

class Cat :public Animal {
    virtual void sound() {

    }
};

int main()
{

}
