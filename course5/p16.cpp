#include <iostream>
using namespace std;


void print_seq_of_chars() {
    for (short i = 65; i < 91; i++)
    {
        for (short j = 65; j < 91; j++)
        {     
            for (short k = 65; k < 91; k++)
                cout << char(i) << char(j) << char(j) << "\n";
            
        }
        
    }
    
}

int main() {
    print_seq_of_chars();
    return 0;
}
