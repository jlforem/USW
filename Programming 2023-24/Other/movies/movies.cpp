#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MovieData {
private:
    string title;
    string director;
    int yearReleased;
    int runningTime;
    int productionCost;
    int firstYearRevenue;
public:
    MovieData(string title, string director, int yearReleased, int runningTime, int productionCost, int firstYearRevenue) {
        this->title = title;
        this->director = director;
        this->yearReleased = yearReleased;
        this->runningTime = runningTime;
        this->productionCost = productionCost;
        this->firstYearRevenue = firstYearRevenue;
    }

    void setMovie() {
        getline(cin, title);
        getline(cin, director);
        cin >> yearReleased;
        cin >> runningTime;
        cin >> productionCost;
        cin >> firstYearRevenue;
    }

    void getMovie() {
        cout << "Movie Title: " << title << "\n";
        cout << "Director: " << director << "\n";
        cout << "Release Year: " << yearReleased << "\n";
        cout << "Run Time: " << runningTime << "\n";
        cout << "Profit: $" << firstYearRevenue - productionCost << "\n";
    }
};
int main()
{
    string title;
    string director;
    int yearReleased = 0;
    int runningTime = 0;
    int productionCost = 0;
    int firstYearRevenue = 0;
    
    MovieData movie1(title, director, yearReleased, runningTime, productionCost, firstYearRevenue);
    MovieData movie2(title, director, yearReleased, runningTime, productionCost, firstYearRevenue);
    movie1.setMovie();
    movie1.getMovie();
    cin.ignore();
    cout << "\n";
    movie2.setMovie();
    movie2.getMovie();
}
