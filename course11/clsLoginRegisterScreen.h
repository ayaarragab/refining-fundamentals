#pragma once
#include "clsScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
  static void _print_dashs()
  {
    cout << setw(20) << left << "" << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n";
    ;
  }

  static string _tabs(int num)
  {
    string t = "";
    for (short i = 0; i < num; i++)
      t.append("\t");
    return t;
  }

  static void _print_header(short vec_length)
  {
    cout << setw(37) << left << "" << "  Users List (" << vec_length << ") User(s).\n";
    _print_dashs();

    cout << setw(20) << left << "" << "| " << left << setw(15) << "DateTime"
         << "| " << left << setw(20) << "Username"
         << "| " << left << setw(20) << "Password"
         << "| " << left << setw(14) << "Permissions"
         << "\n";

    _print_dashs();
  }
  static void _PrintLine(string line)
  {
    vector<string> vec;
    clsString::words_to_vec(line, vec, "//#");
    cout << setw(20) << left << "" << "| " << left << setw(15) << vec[0]
         << "| " << left << setw(20) << vec[1]
         << "| " << left << setw(20) << vec[2]
         << "| " << left << setw(14) << vec[3]
         << "\n";
  }

public:
  static void ShowLoginRegisterScreen() {
    vector<string> users = clsUser::GetLoggedInUsers();
    _print_header(users.size());
    for (string &u: users)
      _PrintLine(u);
  }
};