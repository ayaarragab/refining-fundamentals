#include <iostream>
using namespace std;

const string PASSWORD = "ZZZ";

void find_password() {
    int trails = 0;
    for (short i = 65; i < 91; i++)
    {
        for (short j = 65; j < 91; j++)
        {     
            for (short k = 65; k < 91; k++) {
                string word = "";
                word.append(1, char(i));
                word.append(1, char(j));
                word.append(1, char(k));
                if (PASSWORD == word) {
                    cout << "Password is " << word << "\n";
                    cout << "Found after " << trails << " Trail(s)\n";
                    break;
                }
                ++trails;
            }
            
        }
        
    }
    
}

int main() {
    find_password();
    return 0;
}
