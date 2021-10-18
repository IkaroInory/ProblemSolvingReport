#include <iostream>
#include <string>

using namespace std;

class CDate
{
private:
    int year;
    int month;
    int day;
public:
    CDate() : CDate(0, 0, 0) {}
    CDate(int y, int m, int d) : year(y), month(m), day(d) {}

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    int getDayofYear()
    {
        int i, sum = day;
        int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapYear())
            for (i = 0;i < month;i++)   sum += b[i];
        else
            for (i = 0;i < month;i++)   sum += a[i];

        return sum;
    }
    static int getDayofYear(CDate _date) {
        int i, sum = _date.day;
        int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

        if (_date.isLeapYear())
            for (i = 0;i < _date.month;i++)   sum += b[i];
        else
            for (i = 0;i < _date.month;i++)   sum += a[i];

        return sum;
    }
    bool isEmpty() {
        return year == 0 && month == 0 && day == 0;
    }
};

class software {
private:
    string name;
    char type;
    CDate date;
    char save;

    string getType() {
        if (type == 'O') return "original";
        if (type == 'B') return "backup";
        if (type == 'T') return "trial";

        return "";
    }
    string getMedia() {
        if (save == 'D') return "optical disk";
        if (save == 'U') return "USB disk";
        if (save == 'H') return "hard disk";

        return "";
    }
    string getDate() {
        if (date.isEmpty()) return "this software has unlimited use";
        if (CDate::getDayofYear({ 2015,4,7 }) > date.getDayofYear()) return "this software has expired";
        else {
            int dd = date.getDayofYear() - CDate::getDayofYear({ 2015,4,7 });
            return "this software is going to be expired in " + to_string(dd) + " days";
        }
    }
public:
    software(string _name, char _type, CDate _date, char _save) : name(_name), type(_type), date(_date), save(_save) {}
    software(const software& _software) {
        name = _software.name;
        type = 'B';
        date = _software.date;
        save = 'H';
    }

    string getInfo() {
        return "name:" + name + '\n'
            + "type:" + getType() + '\n'
            + "media:" + getMedia() + '\n'
            + getDate() + '\n';
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string _name;
        char _type, _save;
        int _y, _m, _d;

        cin >> _name;
        cin >> _type >> _save >> _y >> _m >> _d;
        CDate date(_y, _m, _d);
        software temp(_name, _type, date, _save);
        cout << temp.getInfo() << endl;
        software copy(temp);
        cout << copy.getInfo() << endl;
    }
    return 0;
}