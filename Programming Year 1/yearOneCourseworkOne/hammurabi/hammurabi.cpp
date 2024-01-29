#include <iostream>
#include <cstdlib>
using namespace std;

/*
NOTES SECTION

currentYear
starvationThisYear
populationIncrease
population
acresOwnedByCity
bushelHarvestPerAcre
rats
bushelStorage
landPrice (17-

buying/selling acres
how many bushels to feed the people
how many acres to plant seed on
*/


class Player {
private:
	int currentYear = 1, population = 100, acresOwnedByCity = 100, bushelStorageTotal = 2000, bushelHarvestPerAcre = 3, bushelsEatenByRats = 0, landPrice = 17, populationIncrease, plagueDeaths;
public:
	Player (int currentYear, int population, int acresOwnedByCity, int bushelStorageTotal, int landPrice) {
		this->currentYear = currentYear;
		this->population = population;
		this->acresOwnedByCity = acresOwnedByCity;
		this->bushelStorageTotal = bushelStorageTotal;
		this->landPrice = landPrice;
	}
};

int main() 
{

}
