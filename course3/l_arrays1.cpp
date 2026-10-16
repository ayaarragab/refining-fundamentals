#include <iostream>
using namespace std;

void readGrades(int g[3]) {
  for (int i = 0; i < 3; i++)
  {
    g[i] = i;
  }
}
void printGrades(int g[3]) {
  for (int i = 0; i < 3; i++)
  {
    cout << g[i] << "\n";
  }
}
int main() {
  int grades[3];
  readGrades(grades);
  printGrades(grades);
  return 0;
}