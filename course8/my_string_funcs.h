#pragma once
#include "input_funcs.h"
#include <cctype>
#include <vector>

namespace my_string_funcs
{
  string remove_punct(string &s)
  {
    string new_s = "";
    for (short i = 0; i < s.length(); i++)
    {
      if (ispunct(s[i]))
        continue;
      new_s.append(1, s[i]);
    }
    return new_s;
  }

  void words_to_vec(string s, vector<string> &str_vec, string delim)
  {
    short pos = s.find(delim);

    while (pos != string::npos)
    {
      str_vec.push_back(s.substr(0, pos));
      s = s.erase(0, pos + delim.length());
      pos = s.find(delim);
    }

    str_vec.push_back(s);
  }

  void print_vec(vector<string> &str_vec)
  {
    for (string &s : str_vec)
      cout << s << endl;
  }

  string replace_word(string s, string delim, string word, string new_word)
  {
    vector<string> str_vec;
    words_to_vec(s, str_vec, delim);
    string new_str = "";

    for (string s : str_vec)
    {
      if (s != word)
        new_str.append(s);
      else
        new_str.append(new_word);
      new_str.append(delim);
    }

    return new_str.substr(0, new_str.length() - 1);
  }

  string join(vector<string> &vec, string delim)
  {
    string str = "";
    for (string &s : vec)
    {
      str.append(s);
      str.append(delim);
    }

    return str.substr(0, str.length() - 1 - delim.length());
  }

  string join(string arr[], short size, string delim)
  {
    string str = "";
    for (short i = 0; i < size; i++)
    {
      str.append(arr[i]);
      str.append(delim);
    }

    return str.substr(0, str.length() - 1);
  }

} // namespace my_string_funcs
