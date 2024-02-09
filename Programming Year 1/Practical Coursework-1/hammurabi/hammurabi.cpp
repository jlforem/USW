#include <iostream>
#include <fstream>
using namespace std;

class hammurabi {
private:
    int currentYear, population, acresOwnedByCity, bushelStorageTotal, bushelHarvestPerAcre, landPrice, bushelHarvestThisYear;
public:
    hammurabi(int currentYear, int population, int acresOwnedByCity, int bushelStorageTotal, int bushelHarvestPerAcre, int landPrice, int bushelHarvestThisYear) {
        this->currentYear = currentYear;
        this->population = population;
        this->acresOwnedByCity = acresOwnedByCity;
        this->bushelStorageTotal = bushelStorageTotal;
        this->bushelHarvestPerAcre = bushelHarvestPerAcre;
        this->landPrice = landPrice;
        this->bushelHarvestThisYear = bushelHarvestThisYear;
    }
    
    bool gameOver() {
        if (population <= 0) {
            return true;
        }
        if (currentYear > 10) {
            return true;
        }
        return false;
    }

    //getters for hammurabi constructor variables, allows for usage in main
    int getCurrentYear() {
        return currentYear;
    }
    int getPopulation() {
        return population;
    }
    int getAcres() {
        return acresOwnedByCity;
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

    
    int plantSeed(int acresToPlant) {
            bushelHarvestThisYear = (acresToPlant * bushelHarvestPerAcre);
            bushelStorageTotal += bushelHarvestThisYear;
            bushelStorageTotal -= (acresToPlant * 2);
        return bushelHarvestThisYear;
    }

    int ratsEatingBushels() {
        // 20% chance rats eat bushels this year
        if (rand() % 100 <= 20) {
            int bushelsLost = rand() % (300 - 5) + 5; //randomises in the range 5 to 300 each turn to determine the number of bushels lost
            bushelStorageTotal -= bushelsLost;
            return bushelsLost;
        }
    }

    void simulateYear(int populationFed) {
        population = populationFed;
        landPrice = rand() % (26 - 17) + 17; //randomises in the range 17 to 26 each turn to determine the land price
        bushelHarvestPerAcre = rand() % (6 - 2) + 2; //randomises in the range 2 to 6 each turn to determine how much each acre harvested is worth this turn
        currentYear++;
    }

    void displayGameState() {
        cout << "\nCurrent Year: " << currentYear << "\n";
        cout << "Population: " << population << "\n";
        cout << "Acres Owned by City: " << acresOwnedByCity << "\n";
        cout << "Bushel Storage Total: " << bushelStorageTotal << "\n";
        cout << "Bushel Harvest Per Acre: " << bushelHarvestPerAcre << "\n";
        cout << "Land Price: " << landPrice << "\n";
        cout << "\nLast year the city harvested " << bushelHarvestThisYear << " bushels!\n";
    }//display of population increase and starvation rate, maybe add a plague feature to slash the population by half, random chance if == true statement
};

int main() {
    srand(time(NULL)); //seed for landPrice
    hammurabi newGame(0, 100, 1000, 3000, 3, 17, 0);
    int currentYear = newGame.getCurrentYear();
    cout << "Each person needs 20 bushels to survive the year, additional bushels will increase the population next year.\n";

    while (!newGame.gameOver()) {

        int bushelsLost = newGame.ratsEatingBushels();
        newGame.displayGameState();
        cout << "The rats ate " << bushelsLost << " bushels!\n\n";
        cout << "Enter the amount of bushels you want to feed your people: ";
        int bushelsToFeedThisYear;
        int populationFed = 0;
        cin >> bushelsToFeedThisYear;
        if (bushelsToFeedThisYear >= 0) {
            populationFed = newGame.feedPopulation(bushelsToFeedThisYear);
        }
        else {
            cout << "You must have enter a NUMBER 0 or above to feed your population.\n";
            cout << "Enter the amount of bushels you want to feed your people: ";
            cin.ignore();
            cin >> bushelsToFeedThisYear;
            populationFed = newGame.feedPopulation(bushelsToFeedThisYear);
        }
        cout << newGame.getBushelTotal() << " bushels remaining.\n";

        cout << "Enter the amount of acres you want to buy or enter negative to sell: ";
        int acresToBuy = 0;
        cin >> acresToBuy;
        newGame.acresBuyOrSell(acresToBuy);
        cout << newGame.getBushelTotal() << " bushels remaining." << " " << newGame.getAcres() << " acres remain.\n";

        cout << "Enter the amount of acres you want to plant seed on: ";
        int acresToPlant = 0;
        cin >> acresToPlant;
        if ((newGame.getAcres() / 10) <= newGame.getPopulation() && acresToPlant <= (newGame.getBushelTotal()/2) && acresToPlant >= 0 && acresToPlant <= newGame.getAcres()) {
            newGame.plantSeed(acresToPlant);
        }
        else {
            cout << "\nYou must have enough population to work the land that remains at a rate of one person to work 10 acres.\nThere must also be enough seed to plant!\n";
            cout << "Enter the amount of acres you want to plant seed on: ";
            cin.ignore();
            cin >> acresToPlant;
            newGame.plantSeed(acresToPlant);
        }
        newGame.simulateYear(populationFed);
        newGame.gameOver();
    }
    if (newGame.getPopulation() <= 0) {//should the game end early, a failure cout is written with # borders
        for (int i = 0; i < 11; i++) {
            cout << "#############################################################\n";
        }
        cout << "\nGame over! You finished with " << newGame.getPopulation() << " people and " << newGame.getAcres() << " acres of land!\n\n";
        for (int i = 0; i < 10; i++) {
            cout << "#############################################################\n";
        }
    }
    if (currentYear >= 10) {//should the game end by time, a success cout is written
        for (int i = 0; i < 11; i++) {
            cout << "#############################################################\n";
        }
        cout << "\nO Great King Hammurabi, you successfully finished your term with " << newGame.getPopulation() << " people and " << newGame.getAcres() << " acres of land!\n\n";
        for (int i = 0; i < 10; i++) {
            cout << "#############################################################\n";
        }
    }
}