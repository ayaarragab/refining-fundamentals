#include <iostream>
using namespace std;

enum enColor { Red, Blue, Green };

int main() {

  int color;
  enColor color_;

  cin >> color;

  color_ = enColor(color);

  switch (color_)
  {
  case enColor::Red:
    system("4f");
    break;
  
  default:
    break;
  }
  return 0;
}