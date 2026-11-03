#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{

public:
  enum enOption
  {
    ListCurrencies = 1,
    FindCurrency = 2,
    UpdateRate = 3,
    CurrencyCalculator = 4,
    MainMenu = 5
  };

private:
  static enOption _ReadMainMenuOption()
  {
    enOption option = (enOption)clsInputValidate::ReadIntNumberBetween(1, 9, "This is an invalid number");
    return option;
  }

  static void _GoBackToCurrenciesMenu()
  {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("clear");
    ShowCurrencyExchangeScreen();
  }

  static void _ShowListCurrencies() {
    clsCurrenciesScreen::ShowCurrencyListScreen();
  }

  static void _ShowFindCurrency() {}

  static void _ShowUpdateRate() {}

  static void _ShowCurrencyCalculator() {}

  static void _PerformMenuOperation(enOption option)
  {
    switch (option)
    {
    case ListCurrencies:
      system("clear");
      _ShowListCurrencies();
      _GoBackToCurrenciesMenu();
      break;
    case FindCurrency:
      system("clear");
      _ShowFindCurrency();
      _GoBackToCurrenciesMenu();
      break;
    case UpdateRate:
      system("clear");
      _ShowUpdateRate();
      _GoBackToCurrenciesMenu();
      break;
    case CurrencyCalculator:
      system("clear");
      _ShowCurrencyCalculator();
      _GoBackToCurrenciesMenu();
      break;
    case MainMenu:
    {
    }
    break;
    default:
      break;
    }
  }

public:
  static void ShowCurrencyExchangeScreen()
  {

    system("clear");
    _DrawScreenHeader("    Currancy Exhange Main Screen");

    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
    cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
    cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
    cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
    cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
    cout << setw(37) << left << "" << "===========================================\n";

    _PerformMenuOperation((enOption)_ReadMainMenuOption());
  }
};