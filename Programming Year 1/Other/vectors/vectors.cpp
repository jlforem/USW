#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;

    for (int i = 1; i <= 5; i++) {
        a.push_back(i);
    }

    for (auto i = a.cbegin(); i != a.cend(); ++i) {
        cout << *i << " ";
    }
}