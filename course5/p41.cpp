#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

bool is_palindrome(int arr[], short len) {
    short k = len - 1;
    for (short i = 0; i < len; i++)
    {
        if (arr[i] != arr[k])
        {
            cout << "Not a palindrome!\n";
            return false;
        }
        --k;
    }
    cout << "It's palindrome!\n";
    return true;
}

int main() {
    int arr[6] = { 10, 20, 30, 30, 20, 10 };
    is_palindrome(arr, 6);
    return 0;
}
