#include <iostream>
using namespace std;

char readOperator() {
  char c;
  cout << "Enter the operator\n";
  cin >> c;
  return c;
}

int readNum() {
  int num;
  cout << "Enter a number \n";
  cin >> num;
  return num;
}

void read_op1_and_op2(int &op1, int &op2) {
  op1 = readNum();
  op2 = readNum(); 
}

float divide(int a, int b) {
  if (b == 0)
  {
    cout << "Error: Division by zero\n";
    return 0.0;
  }
  return a / b;
}

float map_behavior(char c, int op1, int op2) {

  op1 = float(op1);
  op2 = float(op2);

  switch (c)
  {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '/':
      return divide(op1, op2);
    case '*':
      return op1 * op2;
    default:
      return 0.0;
  }
}

int main() {
  int op1, op2;
  read_op1_and_op2(op1, op2);
  char c = readOperator();
  cout << map_behavior(c, op1, op2) << "\n";
  return 0;
}