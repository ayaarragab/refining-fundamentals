#include <iostream>
using namespace std;

class Calculator {
  private:
    int _result = 0;
  
  public:
    Calculator(int initial_value) {
      _result = initial_value;
    }
    void add(int num) {
      _result += num;
    }
    void subtract(int num) {
      _result -= num;
    }
    void multiply(int num) {
      _result *= num;
    }
    void divide(int num) {
      _result /= num;
    }
    void print_result() {
      cout << _result << endl;
    }
    void clear() {
      _result = 0;
    }
};

int main() {
  Calculator calculator(5);
  calculator.add(1);
  calculator.multiply(10);
  calculator.divide(2);
  calculator.print_result();
  calculator.clear();
  calculator.print_result();
  return 0;
}