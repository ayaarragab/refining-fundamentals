#include <iostream>
using namespace std;

class Calculator {
  private:
    int result = 0;
  
  public:
    void add(int num) {
      result += num;
    }
    void subtract(int num) {
      result -= num;
    }
    void multiply(int num) {
      result *= num;
    }
    void divide(int num) {
      result /= num;
    }
    void printResult() {
      cout << result << endl;
    }
    void clear() {
      result = 0;
    }
};

int main() {
  Calculator calculator;
  calculator.add(1);
  calculator.multiply(10);
  calculator.divide(2);
  calculator.printResult();
  calculator.clear();
  calculator.printResult();
  return 0;
}