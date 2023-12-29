#include <iostream>
#include <string>
using namespace std;

class LoShu {
public:
    //declares a 2d array 3x3 grid as per a loshu magic square
    int loshuSquare[3][3] = {};
    //default constructor calls the getSquare() function
    LoShu() {
        getSquare();
    }
    //function that iterates through each index of the columns and rows using a nested for loop and a do/while to check if the input is valid (1-9 integers)
    void getSquare() {
        for (int column = 0; column < 3; column++) {
            for (int row = 0; row < 3; row++) {
                do {
                    cin >> loshuSquare[column][row];
                } while (loshuSquare[column][row] < 0 || loshuSquare[column][row] > 9);
            }
        }
    }
    //function that initialises variables for the two diagonal sums, the row sum and the column sum and then uses for loops to add the diagonals, columns and rows up
    //it then returns false if the sums do not reach the parameters of a valid loshu magic square and true otherwise
    bool isMagicSquare() {

        int sumOfDiagonal1to9 = 0;
        int sumOfDiagonal3to7 = 0;

        for (int i = 0; i <= 2; i++) {
            sumOfDiagonal1to9 = sumOfDiagonal1to9 + loshuSquare[i][i];
            sumOfDiagonal3to7 = sumOfDiagonal3to7 + loshuSquare[i][2 - i];
        }
        int sumOfColumn = 0;
        int sumOfRow = 0;
        for (int column = 0; column <= 2; column++) {
            for (int row = 0; row <= 2; row++) {
                sumOfColumn = sumOfColumn + loshuSquare[row][column];
                sumOfRow = sumOfRow + loshuSquare[column][row];
            }
        }
        if (sumOfDiagonal1to9 != 15 || sumOfDiagonal3to7 != 15 || sumOfColumn != 45 || sumOfRow != 45) {
            return false;
        }
        return true;
    }
    //print fucntion for the magic square, once again makes use of a nested for loop to print the 2d array as per the exercise specs.
    void outputLoShu() {
        for (int column = 0; column <= 2; column++) {
            cout << "\n";
            for (int row = 0; row <= 2; row++) {
                cout << loshuSquare[column][row];
                cout << " ";
            }
        }
        cout << "\n\n";
    }
};

int main()
{
    //creates a new square and runs it through the output function and a ternery to use isMagicSquare() and the required output following it
    LoShu newSquare;
    newSquare.outputLoShu();
    string magicSqaureResult = (newSquare.isMagicSquare() == true) ? "It is a magic square" : "It is not a magic square";
    cout << magicSqaureResult << "\n";
}