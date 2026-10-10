#include <iostream>
#include <cmath>
using namespace std;

float readNum(string message) {
    float n;
    cout << message;
    cin >> n;
    return n;
}

int my_round(float num) {
    float num_copy = num * 10;
    short d = int(num_copy) % 10;
    if (d >= 5)
        ++num;
    return num;
}

int main() {
    float num = readNum("Enter number:\n");
    cout << "C++ round()" << round(num) << "\n";
    cout << "My round()" << my_round(num) << "\n";
    return 0;
}
