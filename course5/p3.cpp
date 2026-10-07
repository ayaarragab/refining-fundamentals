#include <iostream>
#include <cmath>
using namespace std;

short readNum() {
    short n;
    cout << "Enter a number\n";
    cin >> n;
    return n;
}


short sum_divisors(short num) {
    short upper_limit = ceil(num / 2);
    short sum = 0;
    for (short i = 1; i <= upper_limit; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}

bool is_perfect(short num) {
    return sum_divisors(num) == num;
}

void print_whether_perfect(short num) {
    if (is_perfect(num))
        cout << "Perfect\n";
    else
        cout << "Not perfect\n";
}

int main() {
    short num = readNum();
    print_whether_perfect(num);
    return 0;
}
