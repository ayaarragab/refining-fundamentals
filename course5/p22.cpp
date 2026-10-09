#include <iostream>
using namespace std;

short readNum(string message) {
    short n;
    cout << message;
    cin >> n;
    return n;
}

void print_array(short array[], short length) {
    for (short i = 0; i < length; i++)
        cout << array[i];
    cout << "\n";
}


void create_and_fill_array_and_get_occurances(short length, short num) {
    short array[length];
    short freq = 0;
    for (short i = 0; i < length; i++)
    {
        array[i] = readNum("Enter number " + to_string(i + 1) + ":\n");
        if (array[i] == num)
            ++freq;
    }
    print_array(array, length);
    cout << "Number (" << num << ") Repeated (" << freq << ") Time(s)\n"; 
}


int main() {
    short length = readNum("Enter array length: \n");
    short num = readNum("Enter number to count its occurances:\n");
    create_and_fill_array_and_get_occurances(length, num);
    return 0;
}
