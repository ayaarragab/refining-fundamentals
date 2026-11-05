#include <bits/stdc++.h>
using namespace std;

void AllocateMatrix(int **matrix, int i, int r, int c) {
    if (i == r)
        return;
    
    matrix[i] = new int[c];
    AllocateMatrix(matrix, i + 1, r, c);
}

void FillMatrix(int **matrix, int i, int j, int r, int c) {
    if (i == r)
        return;

    cin >> matrix[i][j];
    if (j == c - 1)
    {
        j = 0;
        FillMatrix(matrix, i + 1, j, r, c);
    } else
        FillMatrix(matrix, i, j + 1, r, c);
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;

    cin >> r;
    cin >> c;

    int **matrix1 = new int*[r];
    int **matrix2 = new int*[r];

    AllocateMatrix(matrix1, 0, r, c);
    AllocateMatrix(matrix2, 0, r, c);

    FillMatrix(matrix1, 0, 0, r, c);
    FillMatrix(matrix2, 0, 0, r, c);

    return 0;
}
