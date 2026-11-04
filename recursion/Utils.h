#pragma once
#include <bits/stdc++.h>
using namespace std;

class Utils
{
public:
  static int* inputArray(int &size) {
      cin >> size;
      int* arr = new int[size];
      int i = 0;
      while (i != size)
          cin >> arr[i++];
      return arr;
  }
};