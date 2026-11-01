#pragma once
#include <iomanip>
#include <iostream>
using namespace std;


class clsScreen {
  protected:
    static void _DrawScreenHeader(string title, string subTitle="") {
      cout << setw(37) << left << "" <<"———————————————————————————————————————————\n";
      cout << setw(37) << left << "" << "\t" << title << endl;
      if (subTitle.length() != 0)
      {
        cout << setw(37)  << subTitle << endl;
      }
      cout << setw(37) << left << "" <<"———————————————————————————————————————————\n";
    }
};