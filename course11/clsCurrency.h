#pragma once
#include <vector>
#include <fstream>
#include "clsInput.h"
#include "clsString.h"
#include "clsHelper.h"

class clsCurrency
{
public:
  enum enMode
  {
    EmptyMode = 0,
    UpdateMode = 1
  };

private:
  enMode _Mode;
  string _Country;
  string _CurrencyCode;
  string _CurrencyName;
  float _Rate;

  static clsCurrency _StrConvertToObj(string line)
  {
    vector<string> splitted;
    clsString::words_to_vec(line, splitted, "#//#");
    return clsCurrency(enMode::UpdateMode, splitted[0], splitted[1], splitted[2], stof(splitted[3]));
  }

  static clsCurrency _GetEmptyObject()
  {
    return clsCurrency(enMode::EmptyMode, "", "", "", 0.0);
  }

  static vector<string> _LoadCurrenciesDataFromFile()
  {
    fstream file;
    vector<string> vCurrencies;
    clsHelper::open_file(file, "Currencies.txt", 'r');
    string line;
    while (getline(file, line))
    {
      vCurrencies.push_back(line);
    }
    file.close();
    return vCurrencies;
  }

  static void _SaveCurrenciesDataToFile(vector<string> vCurrencies)
  {
    fstream file;
    clsHelper::open_file(file, "Currencies.txt", 'w');
    for (string &s : vCurrencies)
    {
      file << s << "\n";
    }
    file.close();
  }

  string _PrepareLineRecord()
  {
    return _Country + "#//#" + _CurrencyCode + "#//#" + _CurrencyName + "#//#" + to_string(_Rate);
  }

  void _Update()
  {
    vector<string> vCurrencies = _LoadCurrenciesDataFromFile();
    for (string &s : vCurrencies)
    {
      clsCurrency Currency = _StrConvertToObj(s);
      if (Currency.CurrencyCode() == CurrencyCode())
      {
        s = _PrepareLineRecord();
        break;
      }
    }
    _SaveCurrenciesDataToFile(vCurrencies);
  }

public:
  enum enSaveResults { svFailedEmptyObject = 0, svSuceeded = 1 };

  clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
  {
    _Country = Country;
    _CurrencyCode = CurrencyCode;
    _CurrencyName = CurrencyName;
    _Mode = Mode;
    _Rate = Rate;
  }

  bool IsEmpty()
  {
    return (_Mode == enMode::EmptyMode);
  }

  string Country()
  {
    return _Country;
  }

  string CurrencyCode()
  {
    return _CurrencyCode;
  }

  string CurrencyName()
  {
    return _CurrencyName;
  }

  void UpdateRate(float NewRate)
  {
    _Rate = NewRate;
  }

  float Rate()
  {
    return _Rate;
  }

  enSaveResults Save()
  {
    switch (_Mode)
    {
    case enMode::EmptyMode:
    {
      return enSaveResults::svFailedEmptyObject;
    }
    case enMode::UpdateMode:
    {
      _Update();
      return enSaveResults::svSuceeded;
    }
    }
  }

  static vector<clsCurrency> getCurrencies()
  {
    vector<string> vLines = _LoadCurrenciesDataFromFile();
    vector<clsCurrency> Currencies;
    for (string &line : vLines)
    {
      Currencies.push_back(_StrConvertToObj(line));
    }
    return Currencies;
  }

  static clsCurrency FindByCode(string Code)
  {
    Code = clsString::UpperAllString(Code);
    vector<clsCurrency> vec = getCurrencies();
    for (clsCurrency &c : vec)
    {
      if (c.CurrencyCode() == Code)
        return c;
    }
    return _GetEmptyObject();
  }

  static clsCurrency FindByName(string Name)
  {
    Name = clsString::UpperAllString(Name);
    vector<clsCurrency> vec = getCurrencies();
    for (clsCurrency &c : vec)
    {
      if (clsString::UpperAllString(c.CurrencyName()) == Name)
        return c;
    }
    return _GetEmptyObject();
  }

  static bool IsCurrencyExist(string Code)
  {
    clsCurrency C1 = clsCurrency::FindByCode(Code);
    return (!C1.IsEmpty());
  }

  static double Convert(clsCurrency from, clsCurrency to, double quantity) {
    double USDQuantity = quantity * from.Rate();
    
    if (to.CurrencyCode() == "USD")
      return USDQuantity;
    
    return USDQuantity * to.Rate();
  }
};