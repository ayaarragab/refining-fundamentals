#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(short from, short to) {
    return rand() % (to - from + 1) + from;
}

int main() {
    srand((unsigned)time(NULL));
    cout << random(1, 10) << endl;
    cout << random(1, 10) << endl;
    cout << random(1, 10) << endl;
}