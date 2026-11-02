#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen: protected clsScreen
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
    static void ShowFindUser() {
      _DrawScreenHeader("Find User Screen");
      clsUser User = clsUser::Find(clsInput::readString("Enter username"));
      if (User.IsEmpty())
        cout << "No Users found with this username" << endl;
      else {
        _PrintUserInfo(User);
      }
    }
};