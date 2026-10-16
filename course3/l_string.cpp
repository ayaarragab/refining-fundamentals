#include <iostream>
#include <string>
using namespace std;

string s1 = "Global";

int main() {
  string s1, s2, s3;
  cout << "Please Enter string 1\n";
  getline(cin, s1);
  
  cout << "Please Enter string 2 as number\n";
  cin >> s2;
  
  cout << "Please Enter string 3 as number\n";
  cin >> s3;
  
  cout << "************************\n";
  cout << "Characters at 0, 2, 7" << s1[0] << s1[2] << s2[7] << "\n";
  cout << "Concatenation of s1 and s2 is: " << s2 + s3 <<"\n";
  cout << "Summation of them: " << stoi(s2) + stoi(s3) << "\n";
  cout << "This is " << ::s1 << "Variable\n"; 
  return 0;
}