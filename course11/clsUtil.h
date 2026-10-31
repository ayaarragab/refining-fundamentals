#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

private:
    static string _worth_space(int num)
    {
        if (!num)
            return "";
        return " ";
    }
    static string _helper(int Number)
    {
        if (Number == 0)
            return "";

        if (Number > 0 && Number < 20)
        {
            string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            return arr[Number];
        }
        if (Number >= 20 && Number < 99)
        {
            string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            return arr[Number / 10] + _worth_space(Number % 10) + _helper(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
            return "One Hundred" + _worth_space(Number % 100) + _helper(Number % 100);
        if (Number >= 200 && Number <= 999)
            return _helper(Number / 100) + _worth_space(Number / 100) + "Hundred" + _worth_space(Number % 100) + _helper(Number % 100);

        if (Number >= 1000 && Number <= 1999)
            return "One Thousand" + _worth_space(Number % 1000) + _helper(Number % 1000);
        if (Number >= 2000 && Number < 999999)
            return _helper(Number / 1000) + _worth_space(Number / 1000) + "Thousand" + _worth_space(Number % 1000) + _helper(Number % 1000);

        if (Number >= 1000000 && Number <= 1999999)
            return "One Million " + _worth_space(Number % 1000000) + _helper(Number % 1000000);
        if (Number >= 2000000 && Number < 999999999)
            return _helper(Number / 1000000) + _worth_space(Number / 1000000) + "Million" + _worth_space(Number % 1000000) + _helper(Number % 1000000);

        if (Number >= 1000000000 && Number <= 1999999999)
            return "One Billion" + _worth_space(Number % 1000000000) + _helper(Number % 1000000000);
        else
            return _helper(Number) + _worth_space(Number) + " Billion" + _worth_space(Number % 1000000000) + _helper(Number % 1000000000);
    }

public:
    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    static void Srand()
    {
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        // Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        // updated this method to accept mixchars
        if (CharType == MixChars)
        {
            // Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        defualt:
            {
                return char(RandomNumber(65, 90));
                break;
            }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static void Swap(int &A, int &B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double &A, double &B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool &A, bool &B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char &A, char &B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string &A, string &B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate &A, clsDate &B)
    {
        clsDate::swapDates(A, B);
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    static void DisplayError(string message)
    {
        cout << "Error: " << message << endl;
    }

    static string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        return _helper(num);
    }
};
