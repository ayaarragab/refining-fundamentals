#pragma once
#include "clsScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
  static void _print_dashs()
  {
    cout << setw(20) << left << "———————————————————————————————————————————————————————————————————————————————————\n";
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
      cout << "\n" << setw(25) << "" << "Users List (" << vec_length << ") User(s).\n";
      _print_dashs();

      cout << "| " << left << setw(19) << "DateTime"
          << "| " << left << setw(19) << "Username"
          << "| " << left << setw(19) << "Password"
          << "| " << left << setw(14) << "Permissions"
          << endl;

      _print_dashs();
  }
  static void _PrintLine(clsUser::stLoggingRegister user)
  {
    cout <<  "| " << left << setw(19) << user.DateTime
         <<  "| " << left << setw(19) << user.Username
         <<  "| " << left << setw(19) << user.Password
         <<  "| " << left << setw(14) << user.permissions
         << "\n";
  }

public:
  static void ShowLoginRegisterScreen() {
    if (!clsUser::CheckPermissions((clsUser::enPermissions)CurrentUser.GetPermissions(), clsUser::enPermissions::LoginRegister))
    {
      cout << "Access Denied" << endl;
      return;
    }
    
    vector<clsUser::stLoggingRegister> users = clsUser::GetLoggedInUsers();
    _print_header(users.size());
    for (clsUser::stLoggingRegister &u: users)
      _PrintLine(u);
  }
};