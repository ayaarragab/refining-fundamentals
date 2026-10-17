#include <iostream>
using namespace std;

void print_arr(int *arr, int size) {
    for (short i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int* fib(short n) {
    int *seq = new int[n];
    seq[0] = 1;
    seq[1] = 1;
    for (short next_empty_pos = 2; next_empty_pos <= n; next_empty_pos++)
    {
        for (short j = next_empty_pos - 2; j < next_empty_pos; j++)
            seq[next_empty_pos] += seq[j];
    }
    return seq;   
}

int main() {
    int *fib_seq = fib(10);
    print_arr(fib_seq, 10);
    delete[] fib_seq;
    return 0;
}
