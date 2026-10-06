#include <iostream>
#include <cmath>

using namespace std;

struct stDate {
  string days;
  string hours;
  string minutes;
  string seconds;
};

double readSeconds() {
  double num;
  cout << "Enter a number \n";
  cin >> num;
  return num;
}

double get_days(double seconds) {
  return double(seconds) / (24 * 60 * 60);
}

double get_hours(double seconds) {
  double days = get_days(seconds);
  double hours_fraction = days - floor(days);
  return hours_fraction * 24;
}

double get_minutes(double seconds) {
 double hours = get_hours(seconds);
 double minutes_fraction = hours - floor(hours);
 return minutes_fraction * 60;
}

double get_seconds(double seconds) {
 double minutes = get_minutes(seconds);
 double seconds_fraction = minutes - floor(minutes);
 return seconds_fraction * 60;
}

stDate initStruct(double seconds) {
  stDate d;
  string days = to_string(floor(get_days(seconds)));
  string hours = to_string(floor(get_hours(seconds)));
  string minutes = to_string(floor(get_minutes(seconds)));
  string remaining_seconds = to_string(floor(get_seconds(seconds)));
  d.days = days;
  d.hours = hours;
  d.minutes = minutes;
  d.seconds = remaining_seconds;
  return d;
}

string format_duration(stDate date) {
  return date.days + ":" + date.hours + ":" + date.minutes + ":" + date.seconds + "\n";
}

int main() {
  double seconds = readSeconds();
  stDate date = initStruct(seconds);
  cout << format_duration(date); 
}