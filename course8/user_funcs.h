#include "my_string_funcs.h"
#include <fstream>
#include <iomanip>

namespace user_namspc
{
  struct stUser
  {
    string username;
    string password;
    int permissions;
  };

  enum enPermissions {
    All=-1,
    ClientList=1,
    AddClient=2,
    DeleteClient=4,
    UpdateClient=8,
    FindClient=16,
    Transactions=32
  };

  void give_permissions(stUser &user) {
    bool permisson;

    // ALL
    cout << "You want to give this user ALL permissions? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson) {
      user.permissions = -1;
      return;
    }
    // list client
    cout << "You want to give this user [1].ClientList permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)ClientList;
    
      // add client
    cout << "You want to give this user [2].AddClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)AddClient;
    
      // delete client
    cout << "You want to give this user [4].DeleteClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)DeleteClient;
    

      // update client
    cout << "You want to give this user [8].UpdateClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)UpdateClient;

      // Find Client
    cout << "You want to give this user [16].FindClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)FindClient;

    // Transactions
    cout << "You want to give this user [32].FindClient permission? " << endl;
    permisson = input_funcs::wants_to_enter();

    if (permisson)
      user.permissions += (int)FindClient;
  }

  void read_user_data(stUser &user)
  {
    user.username = input_funcs::readString("Enter username:");
    user.password = input_funcs::readString("Enter user password:");
    user.permissions = 0;
    give_permissions(user);
  }

  bool check_access(int userPermissions, enPermissions requiredPermissions) {
    if ((enPermissions)userPermissions == All)
      return true;
    if ((int)requiredPermissions & userPermissions == (int)requiredPermissions)
      return true;
    return false;
  }

} // namespace user_funcs
