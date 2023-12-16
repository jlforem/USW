#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

double getSales(string division) {
    double salesFigure;
    //do while to ask for a sales input into the salesfigure variable and then return it provided the numbe is above 0;
    do {
        cout << "Enter sales for: " << division << "\n";
        cin >> salesFigure;

        if (salesFigure < 0) {
            cout << "invalid";
        }
    } while (salesFigure < 0);
    return salesFigure;
}

void findHighest(double northeast, double southeast, double northwest, double southwest) {
    //max function determines the highest double stored of all the variables
    double highestSalesFigure = max({northeast, southeast, northwest, southwest});
    string highestName = "";
    //if else scans through each variable to find which matches the highestSalesFigure and determines that to be the highest, follows by setting highestName as the respective name
    if (highestSalesFigure == northeast) {
        highestName = "Northeast";
    }
    else if (highestSalesFigure == southeast) {
        highestName = "Southeast";
    }
    else if (highestSalesFigure == northwest) {
        highestName = "Northwest";
    }
    else if (highestSalesFigure == southwest) {
        highestName = "Southwest";
    }
    else {
        highestName = "Error in highestName elseIF";
    }
    
    //couts formatted to the tutorial's specifications, fixed and setprecision to achieve the '.00'
    cout << "The " << highestName << " division had the highest sales this quarter." << "\n";
    cout << fixed << setprecision(2) << "Their sales were $" << highestSalesFigure << "\n";
}

int main()
{
    //variables go through the getSales function to check they are being entered above 0, then are set as the users input
    double northeast = getSales("Northeast");
    double southeast = getSales("Southeast");
    double northwest = getSales("Northwest");
    double southwest = getSales("Southwest");
    //find highest determines the highest number and returns that along with the variable's respective name
    findHighest(northeast, southeast, northwest, southwest);
}