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

void add_array_element(short arr[], short &arr_len, short num) {
    arr[arr_len] = num;
    ++arr_len;
}

bool is_found(short arr[], short len, short element) {
    for (short i = 0; i < len; i++)
    {
        if (arr[i] == element)
            return true;  
    }
    return false;
}

void copy_to_dest_array(short src[], short dest[], short len1, short &len2) {
    for (short i = 0; i < len1; i++) {
        if (!is_found(dest, len2, src[i]))
            add_array_element(dest, len2, src[i]);
    }
}


int main() {
    short arr[10] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90}, arr2[100], len2;
    copy_to_dest_array(arr, arr2, 10, len2);
    print_array(arr2, len2);
    return 0;
}
