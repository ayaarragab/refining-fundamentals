#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInput.h"
#include "clsUtil.h"
using namespace std;

class clsAddNewUserScreen: protected clsScreen
{
  private:
    static void _GivePermissions(clsUser &user)
    {
      bool permisson;

      // ALL
      cout << "You want to give this user ALL permissions? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
      {
        user.SetPermissions(-1);
        return;
      }
      // list client
      cout << "You want to give this user [1].ClientList permission? " << endl;
      permisson = clsInput::wants_to_enter();


      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::ClientList);

      // add client
      cout << "You want to give this user [2].AddClient permission? " << endl;
      permisson = clsInput::wants_to_enter();


      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::AddClient);

      // delete client
      cout << "You want to give this user [4].DeleteClient permission? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::DeleteClient);

      // update client
      cout << "You want to give this user [8].UpdateClient permission? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::UpdateClient);

      // Find Client
      cout << "You want to give this user [16].FindClient permission? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::FindClient);

      // Transactions
      cout << "You want to give this user [32].Transactions permission? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::Transactions);

      // Manage Users
      cout << "You want to give this user [64].Manage Users permission? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::ManageUsers);

      // Login Register
      cout << "You want to give this user [128].Login Register permission? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::LoginRegister);


      // CurrencyExchange
      cout << "You want to give this user [265].Currency Exchange permission? " << endl;
      permisson = clsInput::wants_to_enter();

      if (permisson)
        user.SetPermissions(user.GetPermissions() + (int)clsUser::CurrencyExchange);
    }

    static void _ReadUserInfo(clsUser &User)
    {
      string FirstName = clsInput::readString("Enter User First Name");
      string LastName = clsInput::readString("Enter User Last Name");
      string Email = clsInput::readString("Enter User Email");
      string Phone = clsInput::readString("Enter User Phone");
      string Username = clsInput::readString("Enter User username");
      string Password = clsInput::readString("Enter Password");
      if (FirstName.length() != 0)
        User.SetFirstName(FirstName);
      if (LastName.length() != 0)
        User.SetLastName(LastName);
      if (Email.length() != 0)
        User.SetEmail(Email);
      if (Phone.length() != 0)
        User.SetPhone(Phone);
      if (Username.length() != 0)
        User.SetUsername(Username);
      if (Password.length() != 0)
        User.SetPassword(clsUtil::EncryptText(Password, 4));
      _GivePermissions(User);
    }

    static void _PrintUserInfo(clsUser User) {
      cout << "Account Name: " << User.GetFirstName() + " " + User.GetLastName() << endl;
      cout << "Account Phone: " << User.GetPhone() << endl;
      cout << "Account Email: " << User.GetEmail() << endl;
      cout << "Account username: " << User.GetUsername() << endl;
      cout << "Account password: " << User.GetPassword() << endl;
      cout << "Account permissions: " << User.GetPermissions() << endl;
    }
  
  public:

    static void ShowAddUserScreen()
    {
      _DrawScreenHeader("Add New User Screen");
      string Username = clsInput::readString("Enter Username");

      clsUser User = clsUser::Find(Username);

      while (!User.IsEmpty())
      {
        cout << "This Username already in use" << endl;
        Username = clsInput::readString("Enter Username");
        User = clsUser::Find(Username);
      }

      User = clsUser::GetAddNewUser(Username);

      _ReadUserInfo(User);

      clsUser::enSaveResults result = User.Save();

      switch (result)
      {
      case clsUser::enSaveResults::svSuceeded:
        cout << "Succeeded!" << endl;
        _PrintUserInfo(User);
        break;

      case clsUser::enSaveResults::svFailedAccountInUse:
        cout << "Account Already in use!" << endl;
        break;

      default:
        break;
      }
    }

};