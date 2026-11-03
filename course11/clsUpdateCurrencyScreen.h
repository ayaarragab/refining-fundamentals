#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateCurrencyScreen : protected clsScreen
{
private:
  static void _PrintCurrency(clsCurrency Currency)
  {
    cout << "\nCurrency Card:";
    cout << "\n___________________";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();
    cout << "\n___________________\n";
  }

  static float _ReadNewRate()
  {
    cout << "\nEnter New Rate: ";
    float NewRate = clsInputValidate::ReadFloatNumber("Invalid");
    return NewRate;
  }

  static void _UpdateCurrencyRate(clsCurrency &Currency)
  {
    char Answer = 'n';
    cout << "\nAre you sure you want to update the rate of this currency y/n? ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
      cout << "\n\nUpdate Currency Rate:";
      cout << "\n_____________________\n";

      Currency.UpdateRate(_ReadNewRate());

      clsCurrency::enSaveResults Result;
      Result = Currency.Save();

      switch (Result)
      {
      case clsCurrency::enSaveResults::svSuceeded:
      {
        cout << "\nCurrency Rate Updated Successfully :-)\n";
        _PrintCurrency(Currency);
        break;
      }
      case clsCurrency::enSaveResults::svFailedEmptyObject:
      {
        cout << "\nError currency was not saved because it's Empty";
        break;
      }
      }
    }
  }

public:
  static void ShowUpdateCurrencyScreen()
  {
    _DrawScreenHeader("Update Currency Screen");

    string CurrencyCode = clsInput::readString("Please Enter Currency Code: ");

    while (!clsCurrency::IsCurrencyExist(CurrencyCode))
    {
      cout << "\nCurrency was not found, choose another one: ";
      CurrencyCode = clsInput::readString("Please Enter Currency Code: ");
    }

    clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
    _PrintCurrency(Currency);
    _UpdateCurrencyRate(Currency);
  }
};