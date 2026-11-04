#include <bits/stdc++.h>
using namespace std;

static int *inputArray(int &size)
{
    cin >> size;
    int *arr = new int[size];
    int i = 0;
    while (i != size)
        cin >> arr[i++];
    return arr;
}

void max_(int *array, int size, int &max_num)
{
    if (size < 0)
        return;
    max_num = max_num < array[size] ? array[size] : max_num;
    max_(array, size - 1, max_num);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int max_num, size;
    int *arr = inputArray(size);
    max_num = arr[0];
    max_(arr, size - 1, max_num);
    delete[] arr;
    cout << max_num << "\n";
    return 0;
}
