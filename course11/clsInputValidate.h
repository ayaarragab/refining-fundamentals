#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsDate.h"
#include "clsString.h"
#include "clsInput.h"

using namespace std;

class clsInputValidate
{
  private:
    template <typename T> static T loop_untill_getting_val(T from, int T, string whenError) {
      int num = clsInput::readNum("Enter a number between" + to_string(from) + " and " + to_string(to));
      
      while(!IsNumberBetween(num, from, to))
      {
        clsUtil::DisplayError(whenError);
        num = clsInput::readNum("Enter a number between" + to_string(from) + " and " + to_string(to));
      }
      return num;
    }

  public:
    template <typename T> static bool IsNumberBetween(T num, T from, T to) {
      return (num >= from && num <= to);
    }

    static bool IsDateBetween(clsDate date, clsDate from, clsDate to) {
      if (from.date1_after_date2(to))
        clsDate::swapDates(from, to); 
      
      return ((date.date1_after_date2(from) || date.date1_equal_date2(from)) && (date.date1_before_date2(to) || date.date1_equal_date2(to)));
    }

    static int ReadIntNumber(string whenError) {
      return clsInput::readNum("Enter an integer number", whenError);
    }

    static double ReadDblNumber(string whenError) {
      double number;
      cout << "Enter a double Number" << endl;
      cin >> number;
      while (cin.fail())
      {
       cout << whenError << endl;
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       cout << "Enter a double Number" << endl;
       cin >> number;
      }
      return number;
    }

    static float ReadFloatNumber(string whenError) {
      float number;
      cout << "Enter a double Number" << endl;
      cin >> number;
      while (cin.fail())
      {
       cout << whenError << endl;
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       cout << "Enter a double Number" << endl;
       cin >> number;
      }
      return number;
    }

    static int ReadIntNumberBetween(int from, int to, string whenError) {
      return loop_untill_getting_val(from, to, whenError);
    }

    static float ReadFloatNumberBetween(float from, float to, string whenError) {
      return loop_untill_getting_val(from, to, whenError);
    }

    static double ReadDblNumberBetween(double from, double to, string whenError) {
      return loop_untill_getting_val(from, to, whenError);
    }

    static bool IsValideDate(clsDate date) {
      return date.is_valid_date();
    }
};