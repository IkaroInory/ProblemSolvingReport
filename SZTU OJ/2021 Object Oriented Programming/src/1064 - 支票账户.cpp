#include <iostream>

using namespace std;

class BaseAccount {
protected:
    string name;
    string account;
    double balance;
public:
    BaseAccount(string name, string account, double balance) :
        name(name), account(account), balance(balance) {}

    void deposit(double amount) {
        balance += amount;
    }
    virtual void withdraw(double amount) {
        if (amount > balance)
            cout << "insufficient" << endl;
        else
            balance -= amount;
    }
    virtual void display() {
        cout << name << " "
            << account << " "
            << "Balance:" << balance << endl;
    }
};
class BasePlus : public BaseAccount {
    double limit;
    double limit_sum = 0;
public:
    BasePlus(string name, string account, double balance, double limit = 5000) :
        BaseAccount(name, account, balance), limit(limit) {}

    void withdraw(double amount) {
        if (amount > balance + limit)
            cout << "insufficient" << endl;
        else
            if (amount > balance) {
                limit_sum += amount - balance;
                balance = 0;
            }
            else
                balance -= amount;
    }
    void display() {
        cout << name << " "
            << account << " "
            << "Balance:" << balance << " "
            << "limit:" << limit - limit_sum << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string name, account;
        double balance;
        cin >> name >> account >> balance;
        BaseAccount* temp = nullptr;
        if (account.substr(0, 2) == "BA")
            temp = new BaseAccount(name, account, balance);
        else if (account.substr(0, 2) == "BP")
            temp = new BasePlus(name, account, balance);

        int a, b;
        for (int i = 0; i < 2; i++) {
            cin >> a >> b;
            temp->deposit(a);
            temp->withdraw(b);
        }
        temp->display();

        delete temp;
    }
    return 0;
}