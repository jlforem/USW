#include <iostream>
#include <fstream>
using namespace std;

class hammurabi {
private:
    int currentYear, population, acresOwnedByCity, bushelStorageTotal, bushelHarvestPerAcre, landPrice;
public:
    hammurabi(int currentYear, int population, int acresOwnedByCity, int bushelStorageTotal, int bushelHarvestPerAcre, int landPrice) {
        this->currentYear = currentYear;
        this->population = population;
        this->acresOwnedByCity = acresOwnedByCity;
        this->bushelStorageTotal = bushelStorageTotal;
        this->bushelHarvestPerAcre = bushelHarvestPerAcre;
        this->landPrice = landPrice;
    }
    
    bool gameOver() {
        if (population <= 0) {
            return true;
            cout << "Game over! You finished with " << population << " poeple and " << acresOwnedByCity << " acres of land!\n";
        }
        return false;
    }

    int getAcres() {
        return acresOwnedByCity;
    }

    int getPopulation() {
        return population;
    }

    int getBushelTotal() {
        return bushelStorageTotal;
    }

    void acresBuyOrSell(int buySellAcres) {
        if (buySellAcres > 0) {
            bushelStorageTotal -= buySellAcres * landPrice;
            acresOwnedByCity += buySellAcres;
        }
        else if (buySellAcres < 0) {
            bushelStorageTotal += (buySellAcres * -1) * landPrice;
            acresOwnedByCity -= (buySellAcres * -1);
        }
        //does nothing in the case of '0'
    }



    int feedPopulation(int bushelsToFeedThisYear) {
        if (bushelsToFeedThisYear >= 0 && bushelsToFeedThisYear <= bushelStorageTotal) {
            bushelStorageTotal -= bushelsToFeedThisYear;
            int populationFed = bushelsToFeedThisYear / 20;
            return populationFed;
        }
    }

    void plantSeed(int acresToPlant) {
        if (acresToPlant > 0 && acresToPlant <= acresOwnedByCity) {
            bushelStorageTotal += acresToPlant * bushelHarvestPerAcre;
            bushelStorageTotal -= acresToPlant * 2;
        }
    }

    void simulateYear(int populationFed) {
        population = populationFed;
        landPrice = rand() % (26 - 17) + 17; //randomises in the range 17 to 26 each turn
        bushelHarvestPerAcre = rand() % (6 - 2) + 2; //randomises in the range 2 to 6 each turn
    }

    void displayGameState() {
        cout << "\nCurrent Year: " << currentYear << "\n";
        cout << "Population: " << population << "\n";
        cout << "Acres Owned by City: " << acresOwnedByCity << "\n";
        cout << "Bushel Storage Total: " << bushelStorageTotal << "\n";
        cout << "Land Price: " << landPrice << "\n";
    }//display of population increase and starvation rate, maybe add a plague feature to slash the population by half, random chance if == true statement
};

struct saveGame {
    int currentYear, population, acresOwnedByCity, bushelStorageTotal, bushelHarvestPerAcre, landPrice;
};

int main() {
    srand(time(NULL)); //seed for landPrice
    int currentYear = 1;
    hammurabi newGame(1, 100, 1000, 3000, 5, 17);

    cout << "Each person needs 20 bushels to survive the year, additional bushels will increase the population next year.\n";

    while (!newGame.gameOver()) {
        newGame.displayGameState();
        cout << "Enter the amount of bushels you want to feed your people: ";
        int bushelsToFeedThisYear;
        cin >> bushelsToFeedThisYear;
        int populationFed = newGame.feedPopulation(bushelsToFeedThisYear);
        cout << newGame.getBushelTotal() << " bushels remaining.\n";

        cout << "Enter the amount of acres you want to buy or enter negative to sell: ";
        int acresToBuy;
        cin >> acresToBuy;
        newGame.acresBuyOrSell(acresToBuy);
        cout << newGame.getBushelTotal() << " bushels remaining.\n";

        cout << "Enter the amount of acres you want to plant seed on: ";
        int acresToPlant;
        cin >> acresToPlant;
        if ((newGame.getAcres()/10) <= newGame.getPopulation()) {
            newGame.plantSeed(acresToPlant);
        }
        else {
            cout << "You must have enough population to work the land at a rate of one person to work 10 acres.\n";
            cout << "Enter the amount of acres you want to plant seed on: ";
            cin.ignore();
            cin >> acresToPlant;
        }
        

        newGame.simulateYear(populationFed);
        currentYear++;
        newGame.gameOver();
    }
    if (currentYear < 11) {
        newGame.gameOver() == true;
    }
}