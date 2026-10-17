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

int count_in_matrix(int *m, int num, int rows, int cols) {
    int count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (*(m + (i * cols) + j) == num)
                ++count;
        }   
    }
    return count;
}

void is_num_exist(int *m, int num, int rows, int cols) {
    if (count_in_matrix(m, num, rows, cols) > 0)
        cout << "Exist" << endl;
    else
        cout << "Not Exist" << endl;
}

int main() {
    srand((unsigned)time(NULL));
    
    int *matrix = new int[3 * 3];
    fill_matrix_with_ordered_numbers(matrix, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(matrix, 3, 3);
    is_num_exist(matrix, 4, 3, 3);
    delete[] matrix;
    return 0;
}