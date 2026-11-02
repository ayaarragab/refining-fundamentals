#pragma once
#include <iomanip>
#include <iostream>
#include "Global.h"
#include "clsDate.h"
using namespace std;


class clsScreen {
  protected:
    static void _DrawScreenHeader(string title, string subTitle="") {
      cout << setw(37) << left << "" <<"———————————————————————————————————————————\n";
      cout << setw(37) << left << "" << "\t" << title << endl;
      cout << setw(37) << left << "" << "\tUser:" << CurrentUser.GetUsername() << endl;
      cout << setw(37) << left << "" << "\tToday's Date:" << clsDate().date_to_str() << endl;
      if (subTitle.length() != 0)
      {
        cout << setw(37)  << subTitle << endl;
      }
      cout << setw(37) << left << "" <<"———————————————————————————————————————————\n";
    }
};