#include <iostream>

using namespace std;

class card {
protected:
    int no;
    string name;
    int limit;
    float total = 0;
    int s = 0;
public:
    card(int no, string name, int limit) :no(no), name(name), limit(limit) {}

    void pay(float m) {
        if (m + total > limit)
            return;
        total += m;
        s += m;
    }
    void rt(float m) {
        total -= m;
        s -= (int)m;
    }
    void display() {
        cout << no << " " << name << " " << total << " " << s << endl;
    }
};
class vip {
protected:
    int no;
    string name;
    int s = 0;
public:
    vip(int no, string name) :no(no), name(name) {}

    void display() {
        cout << no << " " << s << endl;
    }
};
class p : public card, public vip {
public:
    p(string name, int cn, int vn, int limit) : card(cn, name, limit), vip(vn, name) {}

    void buy(float m) {
        total += m;
        card::s += m;
        vip::s += m;
    }
    void change(int n) {
        card::s -= n;
        vip::s += n / 2;
    }
};

int main() {
    int vn, cn, limit;
    string name;
    cin >> vn >> cn >> name >> limit;
    int t;
    cin >> t;
    p temp(name, cn, vn, limit);
    while (t--) {
        char op;
        cin >> op;
        if (op == 'o') {
            float m;
            cin >> m;
            temp.buy(m);
        }
        else if (op == 'c') {
            float m;
            cin >> m;
            temp.pay(m);
        }
        else if (op == 'q') {
            float m;
            cin >> m;
            temp.rt(m);
        }
        else {
            float m;
            cin >> m;
            temp.change(m);
        }
    }
    temp.vip::display();
    temp.card::display();
    return 0;
}