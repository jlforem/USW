#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;
//currentYear doesnt save properly, returns 0 but the rest work. Have to work on the game not ending when a string is inputted. do uml diagram and report
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
        if ((rand() % 100) <= 20) {
            int topRangeBushelStorage = round(bushelStorageTotal * 0.3);
            int bottomRangeBushelStorage = round(bushelStorageTotal * 0.05);
            int bushelsLost = rand() % (topRangeBushelStorage + bottomRangeBushelStorage) + bottomRangeBushelStorage; //randomises in the range 5 to 300 each turn to determine the number of bushels lost
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

    void save(const string& gameSave) {
        ofstream out(gameSave);
        if (out.is_open()) {
            out << currentYear << "\n";
            out << population << "\n";
            out << acresOwnedByCity << "\n";
            out << bushelStorageTotal << "\n";
            out << bushelHarvestPerAcre << "\n";
            out << landPrice << "\n";
            out << bushelHarvestThisYear << "\n";
        }
    }

    bool load(const string& gameSave) {//referencing the gameSave file allows the function to modify the original string without needing to make a copy
        ifstream in(gameSave); //opens the file in read mode to retrieve the data from the file and overwrite the new game variables before starting the game
        if (in.is_open()) {//checks if the file was opened successfully
            in >> currentYear;
            currentYear += 1; //currentYear was returning one game year behind the current variables. this resolve will have to do.
            in >> population;
            in >> acresOwnedByCity;
            in >> bushelStorageTotal;
            in >> bushelHarvestPerAcre;
            in >> landPrice;
            in >> bushelHarvestThisYear;
            return true;
        }
        return false;
    }
};

int main() {
    srand(time(NULL)); //seed for landPrice and ratsEatingBushels
    hammurabi newGame(0, 100, 1000, 3000, 3, 17, 0);
    cout << "Each person needs 20 bushels to survive the year, additional bushels will increase the population next year.\n";
    cout << "\nDo you want to load the last played game? Y to load, N to start a new game!\n";
    char newOrLoadGame;
    cin >> newOrLoadGame;
    if (newOrLoadGame == 'Y') {
        newGame.load("save.txt");
        cout << "\n\nGame state loaded from save.txt" << "\n";
    }

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
        newGame.save("save.txt");// Save the game state
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
    if (newGame.getCurrentYear() >= 10) {//should the game end by time, a success cout is written
        for (int i = 0; i < 11; i++) {
            cout << "#############################################################\n";
        }
        cout << "\nO Great King Hammurabi, you successfully finished your term with " << newGame.getPopulation() << " people and " << newGame.getAcres() << " acres of land!\n\n";
        for (int i = 0; i < 10; i++) {
            cout << "#############################################################\n";
        }
    }
}