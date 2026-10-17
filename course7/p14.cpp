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

void fill_identity_matrix(int* matrix, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
           if (i == j)
            *(matrix + (i * cols) + j) = 1;
           else
            *(matrix + (i * cols) + j) = 0;
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

bool check_left_diagonal(int *m, int rows) {
    int diag_val = *(m);
    for (short i = 0; i < rows; i++)
    {
        if (*(m + (i * rows) + i) != diag_val)
            return false;   
    }
    return true;
}

bool check_other_positions(int *m, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
           if (i == j)
            continue;
            if (*(m + (i * cols) + j) != 0)
                return false;   
        }
    }
    return true;
}

void is_scalar_(int *m, int rows, int cols) {
    if (check_left_diagonal(m, rows) && check_other_positions(m, rows, cols))
        cout << "SCALAR\n";
    else
        cout << "NOT SCALAR\n";
}

int main() {
    srand((unsigned)time(NULL));
    
    int *matrix = new int[3 * 3];
    fill_matrix_with_ordered_numbers(matrix, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(matrix, 3, 3);
    is_scalar_(matrix, 3, 3);
    delete[] matrix;
    return 0;
}