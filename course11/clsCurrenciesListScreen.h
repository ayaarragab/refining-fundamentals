#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesScreen : protected clsScreen
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
      cout << "\n" << setw(25) << "" << "Currencies List (" << vec_length << ").\n";
      _print_dashs();

      cout << "| " << left << setw(30) << "Country Name"
          << "| " << left << setw(19) << "Currency Code"
          << "| " << left << setw(30) << "Currency Name"
          << "| " << left << setw(19) << "Rate"
          << endl;

      _print_dashs();
  }
  static void _PrintLine(clsCurrency currency)
  {
    cout <<  "| " << left << setw(30) << currency.Country()
         <<  "| " << left << setw(19) << currency.CurrencyCode()
         <<  "| " << left << setw(30) << currency.CurrencyName()
         <<  "| " << left << setw(19) << currency.Rate()
         << "\n";
  }

public:
  static void ShowCurrencyListScreen() {
    if (!clsUser::CheckPermissions((clsUser::enPermissions)CurrentUser.GetPermissions(), clsUser::enPermissions::CurrencyExchange))
    {
      cout << "Access Denied" << endl;
      return;
    }
    _DrawScreenHeader("currency List Screen");
    vector<clsCurrency> currencies = clsCurrency::getCurrencies();
    _print_header(currencies.size());
    for (clsCurrency &c: currencies)
      _PrintLine(c);
  }
};