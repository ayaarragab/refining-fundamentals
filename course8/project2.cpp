#include "project_2.h"
#include "client_data_funcs.h"
using namespace project2;

client_data_funcs::stClientData currentclient;

int main() {
  show_login(currentclient);
  return 0;
}