#include <iostream>
#include <string>
using namespace std;

class DrinkMachine {
private:
    string drinkName;
    double drinkPrice;
    int numberOfDrinksLeftInMachine;
    double dailyEarnings;
    double inputMoney;

    void inputMoney() {
        cout << "Input amount: \n";
    }

    void dailyReport() {

    }

public:
    DrinkMachine (string drinkName, double drinkPrice, int numberOfDrinksLeftInMachine){
        this->drinkName = drinkName;
        this->drinkPrice = drinkPrice;
        this->numberOfDrinksLeftInMachine = numberOfDrinksLeftInMachine;
    }

    void displayChoices() {
        cout << "Here are the drink choices: \n";
    }

    void buyDrink() {
        cout << "Please select a drink to purchase.\n";
    }
};

int main()
{
    std::cout << "Hello World!\n";
}