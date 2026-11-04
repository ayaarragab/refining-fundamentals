#include <bits/stdc++.h>
#include "Utils.h"
using namespace std;

void max_(int *array, int size, int &max_num) {
    if (size < 0)
        return;
    max_num = max_num < array[size] ? array[size] : max_num;
    max_(array, size - 1, max_num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int max_num, size;
    int *arr = Utils::inputArray(size);

    max_(arr, size, max_num);
    cout << max_num << "\n";
    return 0;
}
