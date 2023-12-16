/*

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class earthquakes {
private:
    string earthquakeName;
    string earthquakeLocation;
    double earthquakeRichterMagnitude;
public:
    earthquakes(string earthquakeName, string earthquakeLocation, double earthquakeRichterMagnitude) {
        this->earthquakeName = earthquakeName;
        this->earthquakeLocation = earthquakeLocation;
        this->earthquakeRichterMagnitude = earthquakeRichterMagnitude;
    }

    void insertQuake() {
        getline(cin, earthquakeName);
        getline(cin, earthquakeLocation);
        cin >> earthquakeRichterMagnitude;
    }
};

int main()
{
    
}

