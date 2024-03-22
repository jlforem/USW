#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
int main()
{
    /*srand(time(NULL));

    for (int i = 1; i < 11; i++) {
        int random = rand() % (23 - 17 + 1) + 17;
        cout << random << "\n";
    }*/

    int i = 4;

    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;

    

    while (i > 0) {
        cout << "Fuck you too :)\n";
        sleep_for(10ns);
        sleep_until(system_clock::now() + 1s);
        i--;
    }
    cout << "Liv Smells :)";
}