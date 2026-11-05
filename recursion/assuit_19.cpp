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

void sum_(int *array, int size, double &sum)
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

    double sum = 0;

    int N;
    cin >> N;

    int *arr = inputArray(N);

    sum_(arr, N - 1, sum);
    delete[] arr;
    cout << fixed << setprecision(6) << double(sum / N) << "\n";
    return 0;
}
