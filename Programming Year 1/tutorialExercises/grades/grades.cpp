#include <iostream>
using namespace std;
//initialise the 10 student grade array
int studentGradesArray[10] = {};
//getGrade() creates two variables to store the amount of grades over 50 percent and an input of student grade variable for use with a cin
//do while allows the user to resubmit an out of bounds grade
//the if statement counters up the grades over 50 percent by 1 if a grade higher than 50 percent is found
int getGrade() {
    int gradesOver50Percent = 0;
    int inputOfStudentGrade = 0;
    for (int i = 1; i <= 9; i++) {
        do {
            cin >> studentGradesArray[inputOfStudentGrade];
        } while (!(studentGradesArray[inputOfStudentGrade] >= 0 && studentGradesArray[inputOfStudentGrade] <= 100));
        if (studentGradesArray[inputOfStudentGrade] > 50) {
            gradesOver50Percent = gradesOver50Percent + 1;
        }
    }
    return gradesOver50Percent;
}
int main()
{
    cout << "The scores you entered include " << getGrade() << " percentages over 50.\n";
}