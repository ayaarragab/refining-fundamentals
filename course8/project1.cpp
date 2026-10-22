#include "project_1.h"

int main() {
  project1::show_main_menu();
  project1::enOptions option = (project1::enOptions)input_funcs::readNum("Enter option 1-7, 8 for main menu ,or -1 for ending the program:");
  while (option != -1)
  {
    project1::start_program(option);
    option = (project1::enOptions)input_funcs::readNum("Enter option 1-7, 8 for main menu ,or -1 for ending the program:");
    project1::show_main_menu();
  }
  return 0;
}