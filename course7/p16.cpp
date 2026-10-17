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

int count_of_zeros(int *m, int rows, int cols) {
    int count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (*(m + (i * cols) + j) == 0)
                ++count;
        }
        
    }
    return count;
}

int count_of_non_zeros(int *m, int rows, int cols) {
    int count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (*(m + (i * cols) + j) != 0)
                ++count;
        }
        
    }
    return count;
}

bool is_sparse(int *m, int rows, int cols) {
    return count_of_zeros(m, rows, cols) > count_of_non_zeros(m, rows, cols);
}


int main() {
    srand((unsigned)time(NULL));
    
    int *m = new int[3 * 3];
    fill_identity_matrix(m, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(m, 3, 3);
    cout << "Matrix sparse or not: " << is_sparse(m, 3, 3) << endl;
    delete[] m;
    return 0;
}