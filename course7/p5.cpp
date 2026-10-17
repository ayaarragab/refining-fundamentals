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


int sum_row_or_col(int* matrix, int fixed_index, int num_of_items) {
    matrix = matrix + fixed_index;
    int sum = 0;
    for (short i = 0; i < num_of_items; i++)
        sum += *(matrix + i);
    return sum;
}


int* print_sum_rows_or_cols(int* matrix, int rows=0, int cols=0, bool is_rows=true) {
    int *new_arr = new int;
    int cols_or_rows = is_rows ? rows : cols;
    for (short i = 0; i < cols_or_rows; i++) {
        *(new_arr + i) = sum_row_or_col(matrix, i, cols_or_rows);
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
    int* new_arr = print_sum_rows_or_cols(matrix, 3, 3, false);
    print_array(new_arr, 3);
    delete[] matrix;
    return 0;
}
