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
void add_array_element(short arr[], short &arr_len, short num) {
    arr[arr_len] = num;
    ++arr_len;
}


void copy_to_dest_array(short src[], short dest[], short len1, short &len2) {
    for (short i = 0; i < len1; i++) {
        if (is_prime(src[i]))
            add_array_element(dest, len2, src[i]);
    }
}

int main() {
    short length = readNum("Enter array length: \n"), len2 = 0;
    short array[length], arr2[100];
    fill_array(array, length, enEntryType::Random);
    copy_to_dest_array(array, arr2, length,len2 );
    cout << "Original Array: ";
    print_array(array, length);
    cout << "Copy Array: ";
    print_array(arr2, len2);
    return 0;
}
