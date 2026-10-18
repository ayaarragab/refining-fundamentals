#include "client_data_funcs.h"

int main() {
  vector<client_data_funcs::stClientData> vector;
  vector = client_data_funcs::read_clients_file_and_convert_to_struct("clients.txt");
  client_data_funcs::print_clients(vector);
  return 0;
}
