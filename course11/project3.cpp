#include "clsBankClient.h"
#include <iostream>
using namespace std;

int main() {
  clsBankClient client = clsBankClient::Find("A0121");
  client.Print();
  
  clsBankClient client2 = clsBankClient::Find("A0121", "324343");
  client2.Print();

  return 0;
}