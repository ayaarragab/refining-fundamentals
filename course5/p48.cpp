#include <iostream>
#include <cmath>
using namespace std;

float readNum(string message) {
    float n;
    cout << message;
    cin >> n;
    return n;
}

int my_floor(float num) {
    if (num < 0)
        --num;
    return int(num);
}

int main() {
    float num = readNum("Enter number:\n");
    cout << "C++ floor()" << floor(num) << "\n";
    cout << "My floor()" << my_floor(num) << "\n";
    return 0;
}
