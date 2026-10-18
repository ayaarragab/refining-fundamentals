#include <iostream>
using namespace std;

int readNum(string message)
{
    int n;
    cout << message;
    cin >> n;
    return n;
}

string worth_space(int num) {
    if(!num)
        return "";
    return " ";
}

string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        return helper(num);
    }
string helper(int Number)
{
    if (Number == 0)
        return "";

    if (Number > 0 && Number < 20)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        return arr[Number];
    }
    if (Number >= 20 && Number < 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        return arr[Number / 10] + worth_space(Number % 10) + helper(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
        return "One Hundred" + worth_space(Number % 100) + helper(Number % 100);
    if (Number >= 200 && Number <= 999)
        return helper(Number / 100) + worth_space(Number / 100) +  "Hundred" + worth_space(Number % 100) + helper(Number % 100);

    if (Number >= 1000 && Number <= 1999)
        return "One Thousand" + worth_space(Number % 1000) + helper(Number % 1000);
    if (Number >= 2000 && Number < 999999)
        return helper(Number / 1000) + worth_space(Number / 1000) + "Thousand" + worth_space(Number % 1000) + helper(Number % 1000);


    if (Number >= 1000000 && Number <= 1999999)
        return "One Million " + worth_space(Number % 1000000) + helper(Number % 1000000);
    if (Number >= 2000000 && Number < 999999999)
        return helper(Number / 1000000) + worth_space(Number / 1000000) + "Million" + worth_space(Number % 1000000) + helper(Number % 1000000);        

    if (Number >= 1000000000 && Number <= 1999999999)
        return "One Billion" + worth_space(Number % 1000000000) + helper(Number % 1000000000);            
    else
        return helper(Number) + worth_space(Number) + " Billion" + worth_space(Number % 1000000000) + helper(Number % 1000000000);
}
int main()
{
    cout << numberToWords(31232) << endl;
    return 0;
}
