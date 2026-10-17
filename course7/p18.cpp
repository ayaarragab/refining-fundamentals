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

bool is_num_exist(int *m, int num, int rows, int cols) {
    int count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (*(m + (i * cols) + j) == num)
            {
                return true;
            }
        }   
    }
    return false;
}

bool is_in_vec(vector<int> &vec, int n) {
    for (int &num : vec)
    {
        if (num == n)
            return true;
    }
    return false;
}

void print_intersected_numbers(int *m1, int *m2, int rows, int cols) {
    cout << "Intersected num bers are: ";
    vector<int> intersected_nums = {};
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++) {
            int num = *(m2 + (i * cols) + j);
            if (!is_in_vec(intersected_nums, num) && is_num_exist(m1, num, rows, cols)) {
                cout << num << " ";
                intersected_nums.push_back(num);
            }
        }
    }
    intersected_nums.clear();
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    
    int *matrix = new int[3 * 3];
    fill_matrix_with_ordered_numbers(matrix, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(matrix, 3, 3);

    int *matrix2 = new int[3 * 3];
    fill_matrix_with_random_numbers(matrix2, 3, 3);
    cout << "-----------------------------\n";
    print_matrix(matrix2, 3, 3);
    cout << "-----------------------------\n";
    print_intersected_numbers(matrix2, matrix, 3, 3);
    delete[] matrix;
    delete[] matrix2;
    return 0;
}