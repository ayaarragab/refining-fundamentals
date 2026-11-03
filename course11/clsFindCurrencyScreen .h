#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
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

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country / Name ? ";
        short Answer = clsInputValidate::ReadIntNumberBetween(1, 2, "Enter Number between 1 and 2: ");

        if (Answer == 1)
        {
            string CurrencyCode = clsInput::readString("\nPlease Enter Currency Code: ");
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country = clsInput::readString("\nPlease Enter Country Name: ");
            clsCurrency Currency = clsCurrency::FindByName(Country);
            _ShowResults(Currency);
        }
    }
};