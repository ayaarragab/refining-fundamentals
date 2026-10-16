#include "input_funcs.h"
#include "utils.h"


void fill_matrix_with_random_numbers(int* matrix, int rows, int cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
           *(matrix + i + j) = utils::random(1, 100);
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

int main() {
    srand((unsigned)time(NULL));
    int *matrix = new int;
    fill_matrix_with_random_numbers(matrix, 3, 3);
    print_matrix(matrix, 3, 3);
    delete[] matrix;
    return 0;
}
