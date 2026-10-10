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

void copy_to_dest_array(short src[], short dest[], short len) {
    for (short i = 0; i < len; i++)
        dest[i] = src[i];
}

void swap(short &a, short &b) {
  short temp;
  temp = a;
  a = b;
  b = temp;
}


void reverse(short arr[], short len) {
    short k = len - 1;
    for (short i = 0; i < len / 2; i++)
    {
        swap(arr[k], arr[i]);
        k--;
    }
}

int main() {
    short len = readNum("Enter array length:\n");
    short arr[len];
    fill_array(arr, len, enEntryType::Random);
    cout << "Before reversing:\n";
    print_array(arr, len);
    cout << "After reversing:\n";
    reverse(arr, len);
    print_array(arr, len);
    return 0;
}
