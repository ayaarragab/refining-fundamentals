#pragma once
#include <iostream>
#include <vector>
using namespace std;

class csString
{
  private:
    string _str;
    vector<string> _str_vec;
    string _delim;

  public:
    csString(string str, string delim = " ") {
      this->_str = str;
      csString::words_to_vec(this->_str, this->_str_vec, delim);
      this->_delim = delim;
    };

    csString() {};

    static string remove_punct(string &s)
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

    string remove_punct() {
      return remove_punct(this->_str);
    }
    

    static void words_to_vec(string s, vector<string> &str_vec, string delim)
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

    void words_to_vec(){
      words_to_vec(this->_str, this->_str_vec, this->_delim);
    }
  
    static void print_vec(vector<string> &str_vec)
    {
      for (string &s : str_vec)
        cout << s << endl;
    }

    void print_vec() {
      print_vec(this->_str_vec);
    }

    static string replace_word(string s, string delim, string word, string new_word)
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

    string replace_word(string word, string new_word) {
      return replace_word(this->_str, this->_delim, word, new_word);
    }
  
    static string join(vector<string> &vec, string delim)
    {
      string str = "";
      for (string &s : vec)
      {
        str.append(s);
        str.append(delim);
      }

      return str.substr(0, str.length() - delim.length());
    }

    string join() {
      return join(this->_str_vec, this->_delim);
    }

    static string join(string arr[], short size, string delim)
    {
      string str = "";
      for (short i = 0; i < size; i++)
      {
        str.append(arr[i]);
        str.append(delim);
      }

      return str.substr(0, str.length() - delim.length());
    }
};
