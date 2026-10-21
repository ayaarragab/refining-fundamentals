#include "my_date.h"
using namespace my_date;

int main()
{
    stDate date = { 1, 5, 2022 };
    cout << formatDate(date, "mm/dd/yyyy") << endl;
    return 0;
}
