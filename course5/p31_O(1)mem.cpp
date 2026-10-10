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

void swap(short &a, short &b) {
  short temp;
  temp = a;
  a = b;
  b = temp;
}

void shuffle(short arr[], short len) {
    for (short i = 0; i < len; i++) {
      swap(arr[random(0, len - 1)], arr[random(0, len - 1)]);
    }
}



int main() {
    srand((unsigned)time(NULL));
    short length = readNum("Enter array length: \n");
    short arr1[length];
    fill_array(arr1, length, enEntryType::Random);
    shuffle(arr1, length);
    cout << "Original Array: ";
    print_array(arr1, length);
    cout << "After shuffeling Array: ";
    print_array(arr1, length);
    return 0;
}
