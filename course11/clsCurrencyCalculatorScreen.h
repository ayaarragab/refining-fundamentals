#pragma once
#include "clsScreen.h"
#include "clsInput.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
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
  static vector<clsCurrency> _ReadAndReturnCurrunciesAndQuantity(double &quantity)
  {
    string from_code = clsInput::readString("Enter the Currency Code (From): ");
    string to_code = clsInput::readString("Enter the Currency Code (To): ");

    clsCurrency from = clsCurrency::FindByCode(from_code);
    _PrintCurrency(from);
    clsCurrency to = clsCurrency::FindByCode(to_code);
    _PrintCurrency(to);
    quantity = clsInputValidate::ReadDblNumber("Enter the quantity");
    return {from, to};
  }

public:
  static void ShowCurrencyCalculatorScreen()
  {
    double quantity;
    vector<clsCurrency> FromAndTo = _ReadAndReturnCurrunciesAndQuantity(quantity);
    double result = clsCurrency::Convert(FromAndTo[0], FromAndTo[1], quantity);
    cout << "The result is " << result << endl;
  }
};