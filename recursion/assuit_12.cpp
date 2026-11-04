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

void sum_(int *array, int size, int &sum)
{
    if (size < 0)
        return;
    sum += array[size];
    sum_(array, size - 1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0, size;
    int *arr = inputArray(size);

    sum_(arr, size, sum);
    cout << sum << "\n";
    return 0;
}
