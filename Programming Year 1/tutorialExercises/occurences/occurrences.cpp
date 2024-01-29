#include <iostream>
#include <string>
using namespace std;
//checkOccurences takes in the input and the list to run the if statement 18 times that checks if the nameinput is equal to the name at the index of the name in the list, if it is, it is added to a counter in nameOccurences
int checkOccurences(string nameInput, string nameList[]) {
    int nameOccurences = 0;
    for (int i = 0; i < 18; i++) {
        int nameInList = i;
        if (nameInput == nameList[nameInList]) {
            nameOccurences += 1;
        }
    }
    return nameOccurences;
}

int main()
{
    string name = "";
    string nameList[18] = { "Amy", "Rick", "John", "Patrick", "Marina", "Richard", "Raj", "Marcia", "Amy", "Richard", "John", "Rick", "Patrick", "Amy", "Raj", "John", "Patrick", "Richard" };
    int nameOccurences;
   
    getline(cin, name);
    nameOccurences = checkOccurences(name, nameList);
    if (nameOccurences == 0) {
        cout << "The name " << name << " does not appear in the list";
    }
    else {
        cout << "The name " << name << " appears " << nameOccurences << " times in the list";
    }
}
