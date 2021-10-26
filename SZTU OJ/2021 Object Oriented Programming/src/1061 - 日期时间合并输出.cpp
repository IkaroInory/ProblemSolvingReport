#include <iostream>

using namespace std;

class Date;
class Time;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    friend void Display(Date& d, Time& t);
};
class Time {
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    friend void Display(Date& d, Time& t);
};

void Display(Date& d, Time& t) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", d.year, d.month, d.day, t.hour, t.minute, t.second);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int year, month, day;
        int hour, minute, second;
        cin >> year >> month >> day
            >> hour >> minute >> second;
        Date d(year, month, day);
        Time t(hour, minute, second);
        Display(d, t);
    }
    return 0;
};