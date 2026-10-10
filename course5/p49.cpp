#include <iostream>
#include <cmath>
using namespace std;

float readNum(string message) {
    float n;
    cout << message;
    cin >> n;
    return n;
}

int my_ceil(float num) {
    if (num > 0 && (num - int(num) > 0))
        ++num;
    return int(num);
}

int main() {
    float num = readNum("Enter number:\n");
    cout << "C++ ceil()" << ceil(num) << "\n";
    cout << "My ceil()" << my_ceil(num) << "\n";
    return 0;
}
