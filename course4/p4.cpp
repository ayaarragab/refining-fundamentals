#include <iostream>
using namespace std;

struct stInfo {
  int age;
  bool hasLiscence;
};

void readAge(stInfo &student) {
  cout << "Enter your age\n";
  cin >> student.age;
}

void readHasLiscence(stInfo &student) {
  int hasL;
  cout << "Do you have Liscence? 0: no, 1: yes \n";
  cin >> hasL;
  student.hasLiscence = bool(hasL);
}

void readStudent(stInfo &student) {
  readAge(student);
  readHasLiscence(student);
}

void printDecision(stInfo &student) {
  if (student.age >= 18 || student.hasLiscence)
    cout << "Hired\n";
  else
    cout << "Rejected\n";
}

int main() {
  stInfo s;
  readStudent(s);
  printDecision(s);
  return 0;
}