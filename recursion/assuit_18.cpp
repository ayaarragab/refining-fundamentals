#include <bits/stdc++.h>
using namespace std;

int* inputArray(int size) {
    int* arr = new int[size];
    int i = 0;
    while (i != size)
        cin >> arr[i++];
    return arr;
}


bool isArrayPalindrome(int *array, int size, int fixedSize) {
    if (array[size] != array[fixedSize - size])
        return false;
    else {
        if (size == 0)
            return true;
        return isArrayPalindrome(array, size - 1, fixedSize);
    }
}

void printResult(bool res) {
    if (res)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    int *arr = inputArray(size);
    printResult(isArrayPalindrome(arr, size - 1, size - 1));
    return 0;
}
