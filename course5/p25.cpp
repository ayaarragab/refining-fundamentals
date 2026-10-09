#include <iostream>
#include <cstdlib>
#include <ctime>

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

short get_min_number(short array[], short length) {
    short min_n = array[0];
    for (short i = 0; i < length; i++)
    {
        if (array[i] < min_n)
            min_n = array[i];
    }
    return min_n;
}

int main() {
    short length = readNum("Enter array length: \n");
    short array[length];
    fill_array(array, length, enEntryType::Random);
    print_array(array, length);
    cout << "Minimum number in the array is " << get_min_number(array, length) << "\n";
    return 0;
}
