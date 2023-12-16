#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class StudentPerformance {
private:
    //initialise variables and then default constructor assigns them within to public variables with this pointers
    string name;
    double academicScore;
    double extraCurricularScore;
public:
    StudentPerformance(string name, double academicScore, double extraCurricularScore) {
        this->name = name;
        this->academicScore = academicScore;
        this->extraCurricularScore = extraCurricularScore;
    }
    //gets each inputted line and assigns it to name, then checks if the academic score is between 0 and 100 before moving on to following inputs and repeating this process for extraCurricularScore
    void setStudent() {
        cout << "Enter student name: \n";
        getline(cin, name);
        cout << "Enter student academic score: \n";
        cin >> academicScore;
        while (academicScore < 0 || academicScore > 100) {
            cout << "Retry Entry: \n";
            //cin.ignore() and =0 for security on input being invalidated
            cin.ignore();
            academicScore = 0;
            cin >> academicScore;
        }
        cout << "Enter student extra curricular score: \n";
        cin >> extraCurricularScore;
        while (extraCurricularScore < 0 || extraCurricularScore > 100) {
            cout << "Retry Entry: \n";
            cin.ignore();
            extraCurricularScore = 0;
            cin >> extraCurricularScore;
        }
        
    }
    //get functions here return the required variables for use outside of the class
    string getName() {
        return name;
    }
    double getAcademicScore() {
        return academicScore;
    }
    double getExtraCurricularScore() {
        return extraCurricularScore;
    }
    double getPerformance() {
        return (academicScore * 0.75) + (extraCurricularScore * 0.25);
    }
    //else if runs through the performance score as per the specification and returns a performace score as a string
    string getGrade() {
        int performance = getPerformance();
        if (performance >= 0 && performance <= 39) {
            return "F";
        }
        else if (performance >= 40 && performance <= 49) {
            return "D";
        }
        else if (performance >= 50 && performance <= 59) {
            return "C";
        }
        else if (performance >= 60 && performance <= 69) {
            return "B";
        }
        else if (performance >= 70 && performance <= 100) {
            return "A";
        }
        else {
            return "Invalid performance percentage";
        }
    }    
};
int main()
{
    string name;
    double academicScore = 0.0;
    double extraCurricularScore = 0.0;

    StudentPerformance student(name, academicScore, extraCurricularScore);
    student.setStudent();

    cout << "Student " << student.getName() << "\n";
    cout << "Performance " << setprecision(2) << fixed << student.getPerformance() << "%\n";
    string grade = student.getGrade();
    cout << grade;
}
