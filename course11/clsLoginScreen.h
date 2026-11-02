#include <fstream>
#include "clsScreen.h"
#include "clsInput.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsString.h"
#include "clsHelper.h"
#include "clsDate.h"
#include "Global.h"

class clsLoginScreen: protected clsScreen
{
  private:
    static void _AddToLogFile(string username, string password) {
      string RegisterRecord = clsDate().date_to_str() + "//#" + username + "//#" + password + "//#" + to_string(CurrentUser.GetPermissions());
      fstream file;
      clsHelper::open_file(file, "loginRegister.txt", 'a');
      file << RegisterRecord << endl;
      file.close();
    }
  
    static bool _Login() {
      for (short i = 3; i >= 1; i--)
      {
        string Username = clsInput::readString("Enter Username");
        string Password = clsInput::readString("Enter Password");
        clsUser User = clsUser::Find(Username, Password);
        _AddToLogFile(Username, Password);
        if (User.IsEmpty()) {
          cout << "User Not Found" << endl;
          cout << "You have " << i - 1 << " Trail(s)" << endl;
        }
        else {
          CurrentUser = User;
          clsMainScreen::ShowMainMenue();
          return true;
        };      
      }
      return false;
    }
  public:
    static bool ShowLoginScreen() {
      _DrawScreenHeader("Login Screen");
      return _Login();
    }
};