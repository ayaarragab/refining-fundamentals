#include <iostream>
using namespace std;

struct Professor
{
  string fullName;
  string email;
};


struct Course {
  string name;
  string code;
  Professor prof;
};

int main() {
  Course math;
  Professor mathProf;

  mathProf.email = "ahmed@cu.ed.eg";
  mathProf.fullName = "Ahmed";

  math.prof = mathProf;

  cout << "Enter course name\n";
  cin >> math.name;

  cout << "Enter course code\n";
  cin >> math.code;

  cout << math.code << " | " << math.name << "\n";

  cout << mathProf.email << "\n";

  return 0;
}