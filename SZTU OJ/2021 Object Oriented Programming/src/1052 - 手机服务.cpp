#include <iostream>
#include <string>

using namespace std;

class date {
private:
    int year;
    int month;
    int day;
public:
    date() : date(0, 0, 0) {}
    date(int y, int m, int d) : year(y), month(m), day(d) {}
    string getString() {
        return to_string(year) + '.' + to_string(month) + '.' + to_string(day);
    }
};
class phone {
private:
    char type;
    string num;
    int state;
    date d;
public:
    phone(char _type, string _num, int _state, date _d) : type(_type), num(_num), state(_state), d(_d) {
        cout << "Construct a new phone " << num << endl;
        cout << "类型=" << getType() << "||号码=" << num << "||State=" << getState() << endl;
    }
    phone(const phone& _p) {
        cout << "Construct a copy of phone " << _p.num << endl;
        type = 'D';
        num = _p.num + 'X';
        state = _p.state;
        d = _p.d;
        cout << "类型=" << getType() << "||"
            << "号码=" << num << "||"
            << "State=" << getState() << endl;
    }

    string getType() {
        if (type == 'A') return "机构";
        if (type == 'B') return "企业";
        if (type == 'C') return "个人";
        if (type == 'D') return "备份";

        return "";
    }
    string getState() {
        if (state == 1) return "在用";
        if (state == 2) return "未用";
        if (state == 3) return "停用";

        return "";
    }
    void stopServer() {
        state = 3;
        cout << "Stop the phone " << num << endl;
        cout << "类型=" << getType() << "||"
            << "号码=" << num << "||"
            << "State=" << getState() << " ||"
            << "停机日期=" << d.getString() << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        char _type;
        string _num;
        int _state;
        int _y, _m, _d;
        cin >> _type >> _num >> _state >> _y >> _m >> _d;

        phone p(_type, _num, _state, { _y, _m, _d });
        phone cp(p);
        p.stopServer();
        cout << "----" << endl;
    }
    return 0;
}