#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}


short count(short to_compare_to, int num) {
    short freq = 0;
    while (num > 0)
    {
        short d = num % 10;
        if (to_compare_to == d)
            freq += 1;
        num /= 10;
    }
    
    return freq;
}


int main() {
    int num = readNum("Enter a postitve number:\n");
    short to_compare_with = readNum("Enter a number to count:\n");
    short freq = count(to_compare_with, num);
    cout << "Frequency of Digit " << to_compare_with << " is " << freq << " \n";
    return 0;
}

