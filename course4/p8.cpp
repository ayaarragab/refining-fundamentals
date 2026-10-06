#include <iostream>
using namespace std;

enum enGrade { Pass, Fail };

short readGrade() {
  short grade;
  cout << "Enter your grade\n";
  cin >> grade;
  return grade;
}

enGrade decide(int grade) {
  if (grade >= 50)
    return enGrade::Pass;
  return enGrade::Fail;
}

void printDecision(enGrade grade) {
  if (grade == enGrade::Pass)
    cout << "Passed\n";
  else
    cout << "Failed\n";
}

int main() {
  printDecision(decide(readGrade()));
}