#include <iostream>
#include <string>
using namespace std;

void print_mul_table() {
  for (short i = 0; i < 12; i++)
  {
    cout << i << " Multiplication table\n";
    for (short j = 0; j < 12; j++)
    {
      cout << i << " * " << j << "= " << i * j << "\n"; 
    }
    cout << "=========================\n";
  }
}

void print_pyramid_of_astrisks() {
  for (short i = 9; i > 0; i--)
  {
    for (short j = 0; j < i; j++)
    {  
      cout << "*";
    }
    cout << "\n";
  }
}

void print_pyramid_of_numbers() {
  for (short i = 9; i > 0; i--)
  {
    for (short j = 1; j <= i; j++)
    {  
      cout << j;
    }
    cout << "\n";
  }
}

void print_pyramid_of_numbers_rev() {
  for (short i = 1; i < 10; i++)
  {
    for (short j = 1; j <= i; j++)
    {  
      cout << j;
    }
    cout << "\n";
  }
}

void print_probabilities_ofABC() {
  for (short i = 65; i < 91 ; i++)
  {
    for (short j = i; j < 91; j++)
    {  
      cout << char(i) << char(j) << "\n";
    }
    cout << "\n";
  }
}


void print_pyramids_alpha() {
  for (short i = 65; i <= 70; i++)
  {
    for (short j = 65; j <= i; j++)
    {
      cout << char(j);
    }
    cout << "\n";
  }
}

void print_pyramid_of_numbers_diff() {
  for (short i = 1; i <= 10; i++)
  {
    for (short j = i; j <= 10; j++)
    {  
      cout << j;
    }
    cout << "\n";
  }
}


int main() {
  print_pyramid_of_numbers_diff();
  return 0;
}