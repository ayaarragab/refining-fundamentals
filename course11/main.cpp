#include <iostream>
#include "clsInputValidate.h"

int main()

{
    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
                                       clsDate(8,12,2022), 
                                       clsDate(31, 12, 2022)) << endl;
    
    cout << clsInputValidate::IsDateBetween(clsDate(),
                                       clsDate(31, 12, 2022),
                                       clsDate(8, 12, 2022)) << endl;
    
    int x= clsInputValidate::ReadIntNumber("Invalid Number, Enter again:\n");
    cout << "x=" << x;

    int y = clsInputValidate::ReadIntNumberBetween(1,5,"Number is not within range, enter again:\n");
    cout << "y=" << y;

    double a = clsInputValidate::ReadDoubleNumber("Invalid Number, Enter again:\n");
    cout << "a=" << a;

    double b = clsInputValidate::ReadDoubleNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "b=" << b;

    cout << endl << clsInputValidate::IsValideDate(clsDate(35,12,2022)) << endl;


    return 0;
}