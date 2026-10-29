#pragma once
#include <iostream>
#include <fstream>
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
    static void open_file(fstream &f, string filename, char mode = 'r')
      {
        switch (mode)
        {
        case 'a':
          f.open(filename, ios::out | ios::app);
          break;
        case 'w':
          f.open(filename, ios::out);
          break;
        case 'r':
          f.open(filename, ios::in);
          break;
        default:
          break;
        }
      }
    ~clsHelper();
};

