#include "input_funcs.h"
#include "utils.h"


void fill_matrix_with_random_numbers(int* matrix, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
           *(matrix + (i * cols) + j) = utils::random(1, 5);
    }
}

void fill_matrix_with_ordered_numbers(int* matrix, int rows, int cols) {
    int k = 1;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
           *(matrix + (i * cols) + j) = k++;
    }
}

string with_comma_seperator(int j, int cols) {
    if (j == cols - 1)
        return "";
    return ", ";
}

void print_matrix(int* matrix, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
            cout << *(matrix + (i * cols) + j) << with_comma_seperator(j, cols);
        cout << endl;
    }
}

int sum_row(int* matrix, int row_num, int cols) {
    matrix = matrix + (row_num * cols);
    int sum = 0;
    for (short i = 0; i < cols; i++)
        sum += *(matrix + i);
    return sum;
}

int* print_sum_rows(int* matrix, int rows, int cols) {
    int *new_arr = new int[rows];
    for (short i = 0; i < rows; i++) {
        *(new_arr + i) = sum_row(matrix, i, cols);
    }
    return new_arr;
}


int sum_col(int* matrix, int col_num, int rows) {
    matrix = matrix + col_num;
    int sum = 0;
    for (short i = 0; i < rows; i++)
        sum += *(matrix + rows);
    return sum;
}


int* print_sum_cols(int* matrix, int rows, int cols) {
    int *new_arr = new int[cols];
    for (short i = 0; i < cols; i++) {
        *(new_arr + i) = sum_col(matrix, i, rows);
    }
    return new_arr;
}

void print_array(int* arr, short size) {
    for (short i = 0; i < size; i++)
        cout << *(arr + i) << endl;
}



void transpose_matrix(int *matrix, int cols, int rows) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = i + 1; j < cols; j++) {
            int &x = *(matrix + (i * cols) + j);
            int &y = *(matrix + (j * cols) + i);
            utils::swap(x, y);
        }
    }
}

int* multiply_matrix(int *matrix1, int *matrix2, int cols, int rows) {
    int *new_matrix = new int[rows * cols];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
            *(new_matrix + (i * cols) + j) = *(matrix1 + (i * cols) + j) * *(matrix2 + (i * cols) + j);
    }
    return new_matrix;
}

int main() {
    srand((unsigned)time(NULL));
    
    int *matrix1 = new int[3 * 3];
    fill_matrix_with_ordered_numbers(matrix1, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(matrix1, 3, 3);
    cout << "-----------------------------\n";
    int *matrix2 = new int[3 * 3];
    fill_matrix_with_ordered_numbers(matrix2, 3, 3);
    print_matrix(matrix2, 3, 3);

    cout << "-----------------------------\n";
    int *mul_matrx = multiply_matrix(matrix1, matrix2, 3, 3);
    print_matrix(mul_matrx, 3, 3);

    delete[] mul_matrx;
    delete[] matrix1;
    delete[] matrix2;
    return 0;
}