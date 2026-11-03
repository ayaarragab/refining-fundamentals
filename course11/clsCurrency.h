#pragma once
#include <vector>
#include <fstream>
#include "clsInput.h"
#include "clsString.h"
#include "clsHelper.h"

class clsCurrency
{
  public:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };

  private:
    enMode _Mode;
    string _Country;
    string _Code;
    string _CurrencyName;
    float _Rate;
    
    static clsCurrency _StrConvertToObj(string line) {
      vector<string> splitted;
      clsString::words_to_vec(line, splitted, "//#");
      return clsCurrency(enMode::UpdateMode, splitted[0], splitted[1], splitted[2], stof(splitted[3]));
    }
  
    public:
      clsCurrency(enMode Mode, string Country, string Code, string CurrencyCode, float Rate) {
        _Country = Country;
        _Code = Code;
        _CurrencyName = CurrencyCode;
        _Mode = Mode;
        _Rate = Rate;
      }
  
      static vector<clsCurrency> getCurrencies() {
        fstream file;
        vector<clsCurrency> Currencies;
        clsHelper::open_file(file, "Currencies.txt", 'r');
        string line;
        while (getline(file, line)) {
          Currencies.push_back(_StrConvertToObj(line));
        }
      return Currencies;
  } 
};