#include <iostream>
#include <cmath>

using namespace std;

struct stDate {
  int days;
  int hours;
  int minutes;
  int seconds;
};

int readSeconds() {
  int num;
  do
  {
    cout << "Enter a number \n";
    cin >> num;
  } while (num < 0);
  
  return num;
}

stDate calculate_date(int seconds) {
  float remainder = 0;
  stDate date;

  float days = float(seconds) / (24 * 60 * 60);
  
  remainder = days - floor(days);

  float hours = remainder * 24;

  remainder = hours - floor(hours);
  float minutes = remainder * 60;

  remainder = minutes - floor(minutes);

  float remaining_seconds = floor(remainder * 60);

  date.days = int(days);
  date.hours = int(hours);
  date.minutes = int(minutes);
  date.seconds = int(remaining_seconds);
  
  return date;
}

void printDate(stDate date)
{
    cout << "\n";

    cout << date.days << ":"
         << date.hours << ":"
         << date.minutes << ":"
         << date.seconds << "\n";
}

int main() {
  int seconds = readSeconds();
  stDate date = calculate_date(seconds);
  printDate(date);
  return 0;
}