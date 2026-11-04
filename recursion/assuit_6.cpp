#include <bits/stdc++.h>
using namespace std;

int evenSize(int size) {
    if (size & 1)
        return size - 1;
    return size;
}

void printEvenPositions(int* array, int size) {
    if (size < 0)
        return;
    if (size == 0)
    {
        cout << array[size] << "\n";
        return;
    }
    
    cout << array[size] << " ";
    
    printEvenPositions(array, size - 2);
}

int* inputArray(int &size) {
    cin >> size;
    int* arr = new int[size];
    int i = 0;
    while (i != size)
        cin >> arr[i++];
    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int size;
    int* arr = inputArray(size);

    printEvenPositions(arr, evenSize(size - 1));
    return 0;
}
