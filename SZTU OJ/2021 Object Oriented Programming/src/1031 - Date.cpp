//
//
// Author   IkaroInory
// Date     2021/10/11
//
// All the code of this course and submitted on Online Judge is open source on Github.
// Welcome to reference and verification.
//
// Online Judge
// http://10.11.219.17/JudgeOnline/
// Github Repository
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2021%20Object%20Oriented%20Programming
//
//

#include <iostream>

using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

class Date {
    int year, month, day;
public:
    Date();
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print();
    void addOneDay();
};

Date::Date() : year(0), month(0), day(0) {}
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}
int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }
void Date::setDate(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}
void Date::print() {
    printf("%04d/%02d/%02d\n", year, month, day);
}
void Date::addOneDay() {
    int dc[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isLeap(year)) dc[2]++;

    if (day < dc[month]) day++;
    else {
        if (month < 12) {
            month++;
            day = 1;
        }
        else {
            year++;
            month = 1;
            day = 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int y, m, d;
        cin >> y >> m >> d;

        Date date(y, m, d);
        
        cout << "Today is ";
        date.print();
        cout << "Tomorrow is ";
        date.addOneDay();
        date.print();
    }
    return 0;
}