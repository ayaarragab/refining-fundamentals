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

void fill_matrix_as_palindrome(int* matrix, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols / 2; j++)
        {
            int num = utils::random(1, 10);
            *(matrix + (i * cols) + j) = num;
            *(matrix + (i * cols) + j + cols - 1) = num;
        }
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

bool is_matrix_palindrome(int *m, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols / 2; j++)
        {
            int e1 = *(m + (i * cols) + j);
            int e2 = *(m + (i * cols) + j + cols - 1);
            if ((e1 != e2))
                return false;
        }
    }
    return true;
}

int main() {
    srand((unsigned)time(NULL));
    
    int *matrix = new int[3 * 3];
    fill_matrix_with_ordered_numbers(matrix, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(matrix, 3, 3);

    cout << "Is marix palindrome: " << is_matrix_palindrome(matrix, 3, 3) << endl;

    delete[] matrix;
    return 0;
}