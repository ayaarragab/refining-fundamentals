#include <iostream>
#include <limits>

using namespace std;

namespace input_funcs {
  void print_input_message(string message) {
    cout << message << endl;
  }
  int readNum(string message) {
    print_input_message(message);
    int num;
    cin >> num;
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      print_input_message(message);
      cin >> num;
    }
    
    return num;
  }
  bool wants_to_enter() {
  char c;
  cout << "Enter y\\n\n";
  cin >> c;
  while (cin.fail())
  {
    cin.clear();
    cout << "Please enter a valid character!\n";
    cin >> c;
  }
  return ((c == 'y') || (c == 'Y'));
}
  string readString(string message) {
    print_input_message(message);
    string str;
    getline(cin >> ws, str);
    return str;
  }
  char readCharacter(string message) {
    print_input_message(message);
    char c;
    cin >> c;
    return c;
  }
}