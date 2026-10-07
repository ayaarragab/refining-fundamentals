#include <iostream>
using namespace std;

void column_separator(short i) {
    if (i < 10)
        cout << " ";
    cout << "  " << i << "   ";   
}

void draw_horizontal_line() {
  for (short i = 0; i < 11; i++)
    cout << "———————";
  cout << "\n";
}

void draw_numbers_first_row() {
  cout << "\n                  Multiplication Table From 1 To 10                  \n\n";
  cout << "   "  << "    "; 
  for (short i = 1; i < 11; i++)
    column_separator(i);
  cout << "\n";
}

void draw_inner_in_body(short i) {
    for (short j = i; j < i * 11; j += i)
      column_separator(i);
}

void draw_body_numbers() {
  for (short i = 1; i < 11; i++)
  {
    if (i < 10)
      cout << " ";
    cout << i << "   | ";
    draw_inner_in_body(i);
    cout << "\n";
  }  
}

int main() {
  draw_numbers_first_row();
  draw_horizontal_line();
  draw_body_numbers();
  return 0;
}