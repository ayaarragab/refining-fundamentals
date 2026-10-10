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

bool is_prime(short n) {
    short half_n = floor(n / 2);
    for (short i = 2; i <= half_n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_in_array(short arr[], short val, short length) {
    for (short i = 0; i < length; i++)
    {
        if (arr[i] == val)
            return true;
    }
    return false;
}

short get_unique_random_index(short len, short unique_indices[], short &i) {
    short index = random(0, len - 1);

    while (is_in_array(unique_indices, index, len))
        index = random(0, len - 1);
    
    unique_indices[i] = index;
    ++i;

    return index;
}

void shuffle(short src[], short dest[], short len2) {
    short unique_indices[len2], k = 0;
    for (short i = 0; i < len2; i++) {
        short random_index = get_unique_random_index(len2, unique_indices, k);
        dest[i] = src[random_index];
    }
}



int main() {
    srand((unsigned)time(NULL));
    short length = readNum("Enter array length: \n");
    short arr1[length], arr2[length];
    fill_array(arr1, length, enEntryType::Random);
    shuffle(arr1, arr2, length);
    cout << "Original Array: ";
    print_array(arr1, length);
    cout << "After shuffeling Array: ";
    print_array(arr2, length);
    return 0;
}
