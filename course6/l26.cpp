#include <iostream>
#include <iomanip>
using namespace std;

const char c = 'c';

int main() {
    cout << "----------"<< "----------------------------------------" << "--------------------\n";
    cout << "\tCode\t|\t\tName\t\t|\tProfessor\t\n";
    cout << "----------"<< "-----------------------------------------" << "--------------------\n";
    cout << setw(14) <<"CS123" << setw(25) << "Intro to CS" << setw(25) << "Amr Ghonim\n" << setw(14);
    return 0;
}
