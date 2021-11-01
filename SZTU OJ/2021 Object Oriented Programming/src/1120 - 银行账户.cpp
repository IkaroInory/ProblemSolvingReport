#include <iostream>

using namespace std;

class account {
private:
    double balance;
    double rate;
    int num;
    char type;
public:
    account(double b, double r, int n, char t) :balance(b), rate(r), num(n), type(t) {}

    void c() {
        balance += balance * rate;
        cout << "Account=" << num << "--"
            << "sum=" << balance << endl;
    }
    void print() {
        string ttt = type == 'P' ? "Person" : "Enterprise";
        cout << "Account=" << num << "--"
            << ttt << "--"
            << "sum=" << balance << "--"
            << "rate=" << rate << endl;
    }
};

class current :public account {
public:
    current(double b, int n, char t) : account(b, 0.005, n, t) {}
};
class regular :public account {
public:
    regular(double b, int n, char t) : account(b, 0.015, n + 5e7, t) {}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        char type;
        double balance;
        cin >> num >> type >> balance;
        account* ac = new current(balance, num, type);
        account* ar = new regular(balance, num, type);

        char op;
        for (int i = 0; i < 2; i++) {
            cin >> op;
            account* opp = i == 0 ? ac : ar;
            if (op == 'C') {
                opp->c();
            }
            else if (op == 'P') {
                opp->print();
            }
        }
    }
    return 0;
}