#include "clsScreen.h"
#include "clsInput.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen: protected clsScreen
{
  private:
    static bool _Login() {
      for (short i = 3; i >= 1; i--)
      {
        string Username = clsInput::readString("Enter Username");
        string Password = clsInput::readString("Enter Password");
        clsUser User = clsUser::Find(Username, Password);
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