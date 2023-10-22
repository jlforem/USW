// annualtemperatures.cpp : this program will take in average july temperatures and calculate the new average if the temperature was to rise by 15 percent
//

#include <iostream>

int main()
{
    //initialisation of necesscery variables, tempRise is included for readability later
    double nyAvg = 85;
    double denverAvg = 88;
    double pheonixAvg = 106;
    double tempRise = 1.15;
    //outputs for the base averages and a sentence denoting the 15% increase after the later calcualtions
    std::cout << "NY average is " << nyAvg << "\n";
    std::cout << "Denver average is " << denverAvg << "\n";
    std::cout << "Pheonix average is " << pheonixAvg << "\n";
    std::cout << "If the averages temp rose by 15%\n";
    //calculations of the following years temperatures should they increase on a 15% average
    nyAvg = nyAvg * tempRise;
    denverAvg = denverAvg * tempRise;
    pheonixAvg = pheonixAvg * tempRise;
    //outputs of these calculations
    std::cout << "NY average would be " << nyAvg << "\n";
    std::cout << "Denver average would be " << denverAvg << "\n";
    std::cout << "Pheonix average would be " << pheonixAvg << "\n";
}