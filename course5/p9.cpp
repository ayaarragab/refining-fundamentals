#include <iostream>
using namespace std;


int readNum(string message) {
    int n;
    cout << message;
    cin >> n;
    return n;
}


int count(int to_compare_to, int num) {
    int freq = 0;
    while (num > 0)
    {
        int d = num % 10;
        if (to_compare_to == d)
            freq += 1;
        num /= 10;
    }
    
    return freq;
}

void count_occ_of_each_d(int num) {
  for (int i = 1; i < 10; i++)
  {
    int freq = count(i, num);
    if (freq > 0)
      cout << "Frequency of Digit " << i << " is " << freq << " \n"; 
  }
}


int main()
{
  int num = readNum("Enter a postitve number:\n");
  count_occ_of_each_d(num);
  return 0;
}
