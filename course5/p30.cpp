#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

enum enEntryType { Input, Random };

short readNum(string message) {
    short n;
    cout << message;
    cin >> n;
    return n;
}


int random(short from, short to) {
    return rand() % (to - from + 1) + from;
}

void print_array(short array[], short length) {
    cout << "Array elements are: ";
    for (short i = 0; i < length; i++) {
        cout << array[i];
        if (i != length - 1)
            cout << ", ";
    }
    cout << "\n";
}

void fill_with_input(short array[], short length) {
    for (short i = 0; i < length; i++)
        array[i] = readNum("Array[" + to_string(i) + "]: ");
}

void fill_with_random(short array[], short length) {
    short from = readNum("Enter the smallest number in the range:\n");
    short to = readNum("Enter the largest number in the range:\n");
    for (short i = 0; i < length; i++)
        array[i] = random(from, to);
}

void fill_array(short array[], short length, enEntryType type) {
    switch (type)
    {
    case enEntryType::Input:
        fill_with_input(array, length);
        break;
    case enEntryType::Random:
        fill_with_random(array, length);
        break;
    default:
        break;
    }
}

bool is_prime(short n) {
    short half_n = floor(n / 2);
    for (short i = 2; i <= half_n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


void copy_to_dest_array(short src[], short dest[], short len2) {
    for (short i = 0; i < len2; i++) {
        if (is_prime(src[i]))
            dest[i] = src[i];
        else
            dest[i] = -1;
    }
}

void add_arrays(short arr1[], short arr2[], short arr3[], short length) {
    for (short i = 0; i < length; i++)
        arr3[i] = arr1[i] + arr2[i];
}

int main() {
    short length = readNum("Enter array length: \n");
    short arr1[length], arr2[length], arr3[length];
    fill_array(arr1, length, enEntryType::Random);
    fill_array(arr2, length, enEntryType::Random);
    add_arrays(arr1, arr2, arr3, length);
    print_array(arr1, length);
    print_array(arr2, length);
    print_array(arr3, length);
    return 0;
}
