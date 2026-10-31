#pragma once
#include <iostream>
#include <limits>

using namespace std;

class clsInput {
  public:
    static void print_input_message(string message) {
      cout << message << endl;
    }
    static int readNum(string message) {
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
    static int readNum(string message, string whenError) {
      print_input_message(message);
      int num;
      cin >> num;
      while (cin.fail())
      {
        cout << whenError << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        print_input_message(message);
        cin >> num;
      }
      
      return num;
    }
    static bool wants_to_enter() {
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

    static bool wants_to_enter(string message) {
      char c;
      cout << message << " -> Enter y\\n\n";
      cin >> c;
      while (cin.fail())
      {
        cin.clear();
        cout << "Please enter a valid character!\n";
        cin >> c;
      }
      return ((c == 'y') || (c == 'Y'));
    }

    static string readString(string message) {
      print_input_message(message);
      string str;
      getline(cin >> ws, str);
      return str;
    }

    static string readStringOtional(string message, string fieldName) {
      bool wantsToEnter = wants_to_enter("Do you want to change \"" + fieldName + "\" ?");
      if (wantsToEnter)
      {
        print_input_message(message);
        string str;
        getline(cin >> ws, str);
        return str;
      } else {
        return "";
      }
    }

    static char readCharacter(string message) {
      print_input_message(message);
      char c;
      cin >> c;
      return c;
    }
};