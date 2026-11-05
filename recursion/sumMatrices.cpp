#include <bits/stdc++.h>
using namespace std;

void AllocateMatrix(int **matrix, int i, int r, int c) {
    if (i == r)
        return;
    
    matrix[i] = new int[c];
    AllocateMatrix(matrix, i + 1, r, c);
}

void FillMatrixAndSum(int **matrix, int i, int j, int r, int c, long long &sum) {
    if (i == r)
        return;

    cin >> matrix[i][j];
    sum += matrix[i][j];
    if (j == c - 1)
    {
        j = 0;
        FillMatrixAndSum(matrix, i + 1, j, r, c, sum);
    } else
        FillMatrixAndSum(matrix, i, j + 1, r, c, sum);
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;

    long long sum = 0;

    cin >> r;
    cin >> c;

    int **matrix1 = new int*[r];
    int **matrix2 = new int*[r];

    AllocateMatrix(matrix1, 0, r, c);
    AllocateMatrix(matrix2, 0, r, c);

    FillMatrixAndSum(matrix1, 0, 0, r, c, sum);
    FillMatrixAndSum(matrix2, 0, 0, r, c, sum);

    cout << sum << endl;
    return 0;
}
