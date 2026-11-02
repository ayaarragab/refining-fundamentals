#include "clsScreen.h"
#include "clsInput.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen: protected clsScreen
{
  private:
    static void _Login() {
      bool loginFailed = false;
      do
      {
        string Username = clsInput::readString("Enter Username");
        string Password = clsInput::readString("Enter Password");
        clsUser User = clsUser::Find(Username, Password);
        loginFailed = User.IsEmpty();
        if (loginFailed)
          cout << "User Not Found" << endl;
        else {
          CurrentUser = User;
          loginFailed = false;
        };
      } while (loginFailed);
      clsMainScreen::ShowMainMenue();
    }
  public:
    static void ShowLoginScreen() {
      _DrawScreenHeader("Login Screen");
      _Login();
    }
};