#pragma once
#include <vector>
#include "clsUser.h"
#include "clsScreen.h"

class clsListUsers: protected clsScreen {
  private:
    static void _print_dashs()
    {
      cout << setw(20) << left << "" << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n";;
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
        
        cout << setw(20) << left  << "" << "| " << left << setw(15) << "Full Name"
            << "| " << left << setw(20) << "Email"
            << "| " << left << setw(20) << "Phone"
            << "| " << left << setw(20) << "Username"
            << "| " << left << setw(20) << "Password"
            << "| " << left << setw(14) << "Permissions"
            << "\n";
            
        _print_dashs();
    }
    
    static void _ListUsers()
    {
      vector<clsUser> Users = clsUser::UserList();
      _print_header(Users.size());

      for (clsUser &c : Users)
      {
          cout << setw(20) << left << "" << "| " << left << setw(15) << (c.GetFirstName() + " " + c.GetLastName())
              << "| " << left << setw(20) << c.GetEmail()
              << "| " << left << setw(20) << c.GetPhone()
              << "| " << left << setw(20) << c.GetUsername()
              << "| " << left << setw(20) << c.GetPassword()
              << "| " << left << setw(14) << c.GetPermissions()
              << endl;
      }
      
      _print_dashs();
  } 


  public:
    static void ShowUserList() {
      _DrawScreenHeader("Show User List Screen");
      _ListUsers();
    }
};