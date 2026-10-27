#pragma once
#include <iostream>
using namespace std;

class clsHelper
{
  private:
    /* data */
  public:
    clsHelper(/* args */);
    static int readNum(string message)
      {
          int n;
          cout << message;
          cin >> n;
          return n;
      }
    ~clsHelper();
};

