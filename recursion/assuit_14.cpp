#include <bits/stdc++.h>
using namespace std;

void AllocateMatrix(int **matrix, int i, int r, int c) {
    if (i == r)
        return;
    
    matrix[i] = new int[c];
    AllocateMatrix(matrix, i + 1, r, c);
}

void FillMatrix(int **matrix, int i, int j, int r, int c, bool withZeros=false) {
    if (i == r)
        return;

    if (!withZeros)
        cin >> matrix[i][j];
    else
        matrix[i][j] = 0;

    if (j == c - 1)
    {
        j = 0;
        FillMatrix(matrix, i + 1, j, r, c, withZeros);
    } else
        FillMatrix(matrix, i, j + 1, r, c, withZeros);
    
}

void PrintMatrix(int **matrix, int i, int j, int r, int c) {
    if (i == r)
        return;

    cout << matrix[i][j] << " ";
    if (j == c - 1)
    {
        j = 0;
        cout << "\n";
        PrintMatrix(matrix, i + 1, j, r, c);
    } else
        PrintMatrix(matrix, i, j + 1, r, c);
    
}


void SumMatrices(int **matrix1, int **matrix2, int **sumMatrix, int i, int j , int r, int c) {
    if (i == r)
        return;

    sumMatrix[i][j] += (matrix1[i][j] + matrix2[i][j]);

    if (j == c - 1)
    {
        j = 0;
        SumMatrices(matrix1, matrix2, sumMatrix,  i + 1, j, r, c);
    } else
        SumMatrices(matrix1, matrix2, sumMatrix, i, j + 1, r, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;

    cin >> r;
    cin >> c;

    int **matrix1 = new int*[r];
    int **matrix2 = new int*[r];
    int **sumMatrix = new int*[r];

    AllocateMatrix(matrix1, 0, r, c);
    AllocateMatrix(matrix2, 0, r, c);
    AllocateMatrix(sumMatrix, 0, r, c);

    FillMatrix(matrix1, 0, 0, r, c);
    FillMatrix(matrix2, 0, 0, r, c);
    FillMatrix(sumMatrix, 0, 0, r, c, true);

    SumMatrices(matrix1, matrix2, sumMatrix, 0, 0 , r, c);

    PrintMatrix(sumMatrix, 0, 0, r, c);

    return 0;
}
