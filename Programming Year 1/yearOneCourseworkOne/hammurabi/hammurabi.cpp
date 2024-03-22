#include <iostream>
using namespace std;

class hammurabi {
private:
    int currentYear, population, acresOwnedByCity, bushelStorageTotal, bushelHarvestPerAcre, bushelsEatenByRats, landPrice;
public:
    hammurabi(int currentYear, int population, int acresOwnedByCity, int bushelStorageTotal, int bushelHarvestPerAcre, int bushelsEatenByRats, int landPrice) {
        this->currentYear = currentYear;
        this->population = population;
        this->acresOwnedByCity = acresOwnedByCity;
        this->bushelStorageTotal = bushelStorageTotal;
        this->bushelHarvestPerAcre = bushelHarvestPerAcre;
        this->bushelsEatenByRats = bushelsEatenByRats;
        this->landPrice = landPrice;
    }
    bool gameOver() {
        if (population <= 0 || currentYear >= 11) {
            return true;
        }
        return false;
    }

    void buySellAcres(int acresToBuySell) {
        if (acresToBuySell > 0) {
            bushelStorageTotal -= acresToBuySell * landPrice;
            acresOwnedByCity += acresToBuySell;
        }
        else if (acresToBuySell < 0) {
            bushelStorageTotal += acresToBuySell * landPrice;
            acresOwnedByCity -= acresToBuySell;
        }
    }

    void feedPeople(int bushelsToFeed) {
        if (bushelsToFeed > 0 && bushelsToFeed <= bushelStorageTotal) {
            population += bushelsToFeed / 5;
            bushelStorageTotal -= bushelsToFeed;
        }
    }

    void plantSeed(int acresToPlant) {
        if (acresToPlant > 0 && acresToPlant <= acresOwnedByCity) {
            bushelStorageTotal += acresToPlant * bushelHarvestPerAcre;
            acresOwnedByCity -= acresToPlant;
        }
    }

    void simulateYear() {
        double populationIncrease = population * 0.05;
        population += populationIncrease;
        double starvationThisYear = population * 0.1;
        population -= starvationThisYear;
        bushelStorageTotal -= bushelsEatenByRats;
        landPrice = 17 + rand() % ((23 + 1) - 17);
    }

    void displayGameState() {
        cout << "Current Year: " << currentYear << endl;
        cout << "Population: " << population << endl;
        cout << "Acres Owned by City: " << acresOwnedByCity << endl;
        cout << "Bushel Storage Total: " << bushelStorageTotal << endl;
        cout << "Land Price: " << landPrice << endl;
    }
};

int main() {
    int currentYear = 1;
    hammurabi newGame(1, 100, 100, 2500, 5, 0, 17);

    while (currentYear < 11 && newGame.gameOver() != true) {
        newGame.displayGameState();
        cout << "Enter the amount of people you want to feed: ";
        int peopleToFeed;
        cin >> peopleToFeed;
        newGame.feedPeople(peopleToFeed * 5);

        cout << "Enter the amount of acres you want to buy or sell; enter a negative to sell and a postive to buy: ";
        int acresToSellBuy;
        cin >> acresToSellBuy;
        newGame.buySellAcres(acresToSellBuy);

        cout << "Enter the amount of acres you want to plant seed on: ";
        int acresToPlant;
        cin >> acresToPlant;
        newGame.plantSeed(acresToPlant);

        newGame.simulateYear();
        currentYear++;
        newGame.gameOver();
    }
}