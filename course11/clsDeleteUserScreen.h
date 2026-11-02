#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsDeleteUserScreen: protected clsScreen
{
  private:
    static void _PrintUserInfo(clsUser User) {
      cout << "Account Name: " << User.GetFirstName() + " " + User.GetLastName() << endl;
      cout << "Account Phone: " << User.GetPhone() << endl;
      cout << "Account Email: " << User.GetEmail() << endl;
      cout << "Account username: " << User.GetUsername() << endl;
      cout << "Account password: " << User.GetPassword() << endl;
      cout << "Account permissions: " << User.GetPermissions() << endl;
    }
  
  public:

    static void ShowDeleteUserScreen()
    {
      _DrawScreenHeader("\t\tDelete user screen");
      string username = clsInput::readString("Enter username");

      clsUser User = clsUser::Find(username);

      while (User.IsEmpty())
      {
        cout << "No User Exists with this username" << endl;
        username = clsInput::readString("Enter username");
        User = clsUser::Find(username);
      }
      _PrintUserInfo(User);
      bool deleted = User.Delete();

      if (deleted)
        cout << "User Deleted Successfully" << endl;
      else
        cout << "No User is deleted" << endl;
    }

};