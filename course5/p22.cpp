#include <iostream>
using namespace std;

short readNum(string message) {
    short n;
    cout << message;
    cin >> n;
    return n;
}

void print_array(short array[], short length) {
    cout << "Array elements are: ";
    for (short i = 0; i < length; i++)
        cout << array[i];
    cout << "\n";
}

void fill_array(short array[], short length) {
    for (short i = 0; i < length; i++)
        array[i] = readNum("Array[" + to_string(i) + "]: ");
}

short get_num_frequency(short array[], short length, short num) {
    short freq = 0;
    for (short i = 0; i < length; i++)
    {
        if (array[i] == num)
            ++freq;
    }
    return freq;
}

int main() {
    short length = readNum("Enter array length: \n");
    short num = readNum("Enter number to count its occurances:\n");
    short array[length];
    fill_array(array, length);
    print_array(array, length);
    cout << "Number " << num << " repeated " << get_num_frequency(array, length, num) << " Time(s).\n"; 
    return 0;
}
