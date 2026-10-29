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
    static int loop_untill_getting_val(int from, int to, string whenError) {
      int num = clsInput::readNum("Enter a number between" + to_string(from) + " and " + to_string(to));
      
      while(!IsNumberBetween(num, from, to))
      {
        clsUtil::DisplayError(whenError);
        num = clsInput::readNum("Enter a number between" + to_string(from) + " and " + to_string(to));
      }
      return num;
    }

    static float loop_untill_getting_val(float from, float to, string whenError) {
      float num = clsInput::readNum("Enter an integer number between" + to_string(from) + " and " + to_string(to));
      
      while(!IsNumberBetween(num, from, to))
      {
        clsUtil::DisplayError(whenError);
        num = clsInput::readNum("Enter a float number between" + to_string(from) + " and " + to_string(to));
      }
      return num;
    }

    static double loop_untill_getting_val(double from, double to, string whenError) {
      double num = clsInput::readNum("Enter a number between" + to_string(from) + " and " + to_string(to));
      
      while(!IsNumberBetween(num, from, to))
      {
        clsUtil::DisplayError(whenError);
        num = clsInput::readNum("Enter a float/double number between" + to_string(from) + " and " + to_string(to));
      }
      return num;
    }

  public:
    static bool IsNumberBetween(int num, int from, int to) {
      return (num >= from && num <= to);
    }

    static bool IsNumberBetween(float num, float from, float to) {
      return (num >= from && num <= to);
    }

    static bool IsNumberBetween(double num, double from, double to) {
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

    static double ReadDoubleNumber(string whenError) {
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

    static double ReadDoubleNumberBetween(double from, double to, string whenError) {
      return loop_untill_getting_val(from, to, whenError);
    }

    static bool IsValideDate(clsDate date) {
      return date.is_valid_date();
    }
};