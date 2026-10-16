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

void print_sum_rows(int* matrix, int rows, int cols) {
    for (short i = 0; i < rows; i++)
        cout << "Sum of numbers in row " << i + 1 << " is: " << sum_row(matrix, i, cols) << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int *matrix = new int;
    fill_matrix_with_random_numbers(matrix, 3, 3);
    print_matrix(matrix, 3, 3);
    print_sum_rows(matrix, 3, 3);
    delete[] matrix;
    return 0;
}