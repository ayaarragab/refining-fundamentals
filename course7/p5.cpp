#include "input_funcs.h"
#include "utils.h"


void fill_matrix_with_random_numbers(int* matrix, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
           *(matrix + i + j) = utils::random(1, 5);
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
            cout << *(matrix + i + j) << with_comma_seperator(j, cols);
        cout << endl;
    }
}

int sum_row(int* matrix, int row_num, int cols) {
    matrix = matrix + row_num;
    int sum = 0;
    for (short i = 0; i < cols; i++)
        sum += *(matrix + i);
    return sum;
}

int* print_sum_rows(int* matrix, int rows, int cols) {
    int *new_arr = new int;
    for (short i = 0; i < rows; i++) {
        *(new_arr + i) = sum_row(matrix, i, cols);
    }
    return new_arr;
}


int sum_col(int* matrix, int col_num, int rows) {
    matrix = matrix + col_num;
    int sum = 0;
    for (short i = 0; i < rows; i++)
        sum += *(matrix + i);
    return sum;
}


int* print_sum_cols(int* matrix, int rows, int cols) {
    int *new_arr = new int;
    for (short i = 0; i < cols; i++) {
        *(new_arr + i) = sum_col(matrix, i, rows);
    }
    return new_arr;
}

void print_array(int* arr, short size) {
    for (short i = 0; i < size; i++)
        cout << *(arr + i) << endl;
}

int main() {
    srand((unsigned)time(NULL));
    
    int *matrix = new int;
    fill_matrix_with_random_numbers(matrix, 3, 3);
    print_matrix(matrix, 3, 3);
    int* new_arr = print_sum_cols(matrix, 3, 3);
    print_array(new_arr, 3);
    delete[] matrix;
    return 0;
}
