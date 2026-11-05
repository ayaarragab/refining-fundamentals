#include <bits/stdc++.h>
using namespace std;

static int *inputArray(int N)
{
    int *arr = new int[N];
    int i = 0;
    while (i != N)
        cin >> arr[i++];
    return arr;
}

void sum_(int *array, int size, long long &sum, int elementsToSum)
{
    if (size < 0 || elementsToSum == 0)
        return;
    sum += array[size];
    sum_(array, size - 1, sum, elementsToSum - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sum = 0;

    int N;
    cin >> N;

    int M;
    cin >> M;

    int *arr = inputArray(N);

    sum_(arr, N - 1, sum, M);
    delete[] arr;
    cout << sum << "\n";
    return 0;
}
