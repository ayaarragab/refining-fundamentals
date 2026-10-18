#include <iostream>
using namespace std;

int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int num_of_days(int year) {
    return 365 + (is_leap_year(year) ? 1 : 0);
}

int num_of_hours(int year) {
    return (365 + (is_leap_year(year) ? 1 : 0)) * 24;
}


int num_of_minutes(int year) {
    return (365 + (is_leap_year(year) ? 1 : 0)) * 24 * 60;
}

int num_of_seconds(int year) {
    return (365 + (is_leap_year(year) ? 1 : 0)) * 24 * 60 * 60;
}


int main() {
    cout << num_of_days(2000) << endl;
    cout << num_of_hours(2000) << endl;
    cout << num_of_minutes(2000) << endl;
    cout << num_of_seconds(2000) << endl;
    return 0;
}
