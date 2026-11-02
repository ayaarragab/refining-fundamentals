#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInput.h"
#include "clsScreen.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
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
  }
  static void _UpdateUserInfo(clsUser &User)
  {
    string FirstName = clsInput::readStringOptional("Enter User First Name", "First Name");
    string LastName = clsInput::readStringOptional("Enter User Last Name", "Last Name");
    string Email = clsInput::readStringOptional("Enter User Email", "Enter User Email");
    string Phone = clsInput::readStringOptional("Enter User Phone", "Phone");
    string Username = clsInput::readStringOptional("Enter User username", "Username");
    string Password = clsInput::readStringOptional("Enter Password", "Password");

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
      User.SetPassword(Password);
    bool wantToChangePermissions = clsInput::wants_to_enter("Do you want to change the user permissions?");
    if (wantToChangePermissions)
      _GivePermissions(User);
  }

  static void _PrintUserInfo(clsUser User)
  {
    cout << "Account Name: " << User.GetFirstName() + " " + User.GetLastName() << endl;
    cout << "Account Phone: " << User.GetPhone() << endl;
    cout << "Account Email: " << User.GetEmail() << endl;
    cout << "Account username: " << User.GetUsername() << endl;
    cout << "Account password: " << User.GetPassword() << endl;
    cout << "Account permissions: " << User.GetPermissions() << endl;
  }

public:
  static void ShowUpdateUser()
  {
    string username = clsInput::readString("Enter username");

    clsUser User = clsUser::Find(username);

    while (User.IsEmpty())
    {
      cout << "No User Exists with this username" << endl;
      username = clsInput::readString("Enter username");
      User = clsUser::Find(username);
    }

    _UpdateUserInfo(User);

    clsUser::enSaveResults result = User.Save();
    switch (result)
    {
    case clsUser::enSaveResults::svSuceeded:
      cout << "Succeeded!" << endl;
      break;

    case clsUser::enSaveResults::svFailedEmptyObject:
      cout << "Empty!" << endl;
      break;

    default:
      break;
    }
  }
};
