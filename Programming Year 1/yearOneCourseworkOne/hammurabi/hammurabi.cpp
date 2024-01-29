#include <iostream>
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
landPrice (17-26)

buying/selling acres
how many bushels to feed the people
how many acres to plant seed on#

MODIFICATION: enter the amount of people you want to feed: instead of the amount of bushels you want to feed them: add a bushel total spent display, bushel total spent for acres too
*/
class hammurabi {
private:
	int currentYear, population, acresOwnedByCity, bushelStorageTotal, bushelHarvestPerAcre, bushelsEatenByRats, landPrice;
public:
	hammurabi(int currentYear, int population, int acresOwnedByCity, int bushelStorageTotal, int bushelHarvestPerAcre, int bushelsEatenByRats, int landPrice){
		this->currentYear = currentYear;
		this->population = population;
		this->acresOwnedByCity = acresOwnedByCity;
		this->bushelStorageTotal = bushelStorageTotal;
		this->bushelHarvestPerAcre = bushelHarvestPerAcre;
		this->bushelsEatenByRats = bushelsEatenByRats;
		this->landPrice = landPrice;
	}

	bool gameOver() { 
		if (population <= 0) {
			return true;
		}
		return false;
	}

	void acresBuyOrSell(int buySellAcres) {
		if (buySellAcres > 0) {
			bushelStorageTotal -= buySellAcres * landPrice;
			acresOwnedByCity += buySellAcres;
		}
		else if (buySellAcres < 0) {
			bushelStorageTotal += buySellAcres * landPrice;
			acresOwnedByCity -= buySellAcres;
		}
		//does nothing in the case of '0'
	}
};
int main() 
{
	int currentYear = 1;

	hammurabi newGame(1, 100, 100, 2500, 5, 0, 17);

	if (newGame.gameOver() == false) {
		cout << "Game Over";
	}
	while (currentYear < 11 && newGame.gameOver() != true) {
		
	}
}