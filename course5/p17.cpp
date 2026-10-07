#include <iostream>
using namespace std;

const string PASSWORD = "AAF";

void find_password() {
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
                    cout << "Found after " << k - 65 + 1 << " Trail(s)\n";
                    break;
                }
                
            }
            
        }
        
    }
    
}

int main() {
    find_password();
    return 0;
}
