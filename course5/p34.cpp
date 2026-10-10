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


short search(short arr[], short len, short element) {
    for (short i = 0; i < len; i++)
    {
        if (arr[i] == element)
            return i;  
    }
    return -1;
}

void act_on_search(short &pos, short &order) {
    if (pos == -1)
    {
        cout << "Element not found :-)\n";
        return;
    }
    cout << "Element at position: "<< pos << " \n";
    order = pos + 1;
    cout << "Element at order: "<< order << " \n";
}


int main() {
    short len = readNum("Enter array length:\n");
    short arr[len];
    fill_array(arr, len, enEntryType::Random);
    short element = readNum("Enter element you're searching for:\n");
    short order;
    short position = search(arr, len, element);
    act_on_search(position, order);
    print_array(arr, len);
    return 0;
}
