#include <iostream>
using namespace std;

int readNum(string message)
{
    int n;
    cout << message;
    cin >> n;
    return n;
}

string num_to_words(int num)
{
    if (num == 0)
        return "";

    if (num > 0 && num < 20)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fiveteen", "Sixteen", "Eighteen", "Nineteen" };
        return arr[num];
    }
    if (num >= 20 && num < 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Fourty", "Fivety", "Sixty", "Seventy", "Eighty", "Ninty" };
        return arr[num / 10] + "  " + num_to_words(num % 10);
    }

    if (num >= 100 && num <= 199)
        return "One Hundered" + num_to_words(num % 100);
    if (num >= 199 && num <= 999)
        return num_to_words(num / 100) + " Hundereds " + num_to_words(num % 100);

    if (num >= 1000 && num <= 1999)
        return "One Thousands" + num_to_words(num % 1000);
    if (num >= 2000 && num < 999999)
        return num_to_words(num / 1000) + " Thousands " + num_to_words(num % 1000);


    if (num >= 1000000 && num <= 1999999)
        return "One Million" + num_to_words(num % 1000000);
    if (num >= 2000000 && num < 999999999)
        return num_to_words(num / 1000000) + " Millions " + num_to_words(num % 1000000);        

    if (num >= 1000000000 && num <= 1999999999)
        return "One Billion" + num_to_words(num % 10000000);
    if (num >= 2000000000 && num < 9999999999)
        return num_to_words(num / 100000000) + " Billions " + num_to_words(num % 100000000);                
}

int main()
{
    cout << num_to_words(31232) << endl;
    return 0;
}
