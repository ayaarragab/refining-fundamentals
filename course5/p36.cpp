#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

void allocate_areas(short arr[100], short &real_length) {
    bool addmore = true;
    do
    {
        short num = readNum("Please enter a number:\n");
        arr[real_length] = num;
        addmore = bool(readNum("Do you want to add more numbers? [0] -> No, [1] => Yes:\n"));
        ++real_length;
    } while (addmore);   
}

void print_array(short array[], short length) {
    cout << "Array Length is: " << length << "\n";
    cout << "Array elements are: ";
    for (short i = 0; i < length; i++) {
        cout << array[i];
        if (i != length - 1)
            cout << ", ";
    }
    cout << "\n";
}

int main() {
    short arr[100], real_length = 0;
    allocate_areas(arr, real_length);
    print_array(arr, real_length);
    return 0;
}
