#include <iostream>
using namespace std;

class Calculator {
  private:
    int _result = 0;

  public:
    
    static int numberOfOperations;
  
    Calculator(int initial_value) {
      _result = initial_value;
    }
    void add(int num) {
      _result += num;
      ++numberOfOperations;
    }
    void subtract(int num) {
      _result -= num;
      ++numberOfOperations;
    }
    void multiply(int num) {
      _result *= num;
      ++numberOfOperations;
    }
    void divide(int num) {
      _result /= num;
      ++numberOfOperations;
    }
    void print_result() {
      cout << _result << endl;
    }
    void clear() {
      _result = 0;
      ++numberOfOperations;
    }
    ~Calculator() {
      cout << "End of calculations\n";
    }
};

int Calculator::numberOfOperations = 0;

int main() {
  Calculator calculator(5), calculator2(10);
  calculator.add(1);
  calculator.multiply(10);
  calculator.divide(2);
  calculator.clear();
  calculator2.divide(2);
  calculator2.multiply(2);
  cout << calculator2.numberOfOperations << endl;
  return 0;
}