#include "input_funcs.h"
#include "utils.h"
#include <vector>

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

int max_in_matrix(int *m, int rows, int cols) {
    int max_num = *(m);
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++) {
            if (*(m + (i * cols) + j) > max_num)
                max_num = *(m + (i * cols) + j);
        }
    }
    return max_num;
}

int min_in_matrix(int *m, int rows, int cols) {
    int min_num = *(m);
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++) {
            if (*(m + (i * cols) + j) < min_num)
                min_num = *(m + (i * cols) + j);
        }
    }
    return min_num;
}

int main() {
    srand((unsigned)time(NULL));
    
    int *matrix = new int[3 * 3];
    fill_matrix_with_ordered_numbers(matrix, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(matrix, 3, 3);

    cout << "Max num in matrix: " << max_in_matrix(matrix, 3, 3) << endl;
    cout << "Min num in matrix: " << min_in_matrix(matrix, 3, 3) << endl;

    delete[] matrix;
    return 0;
}