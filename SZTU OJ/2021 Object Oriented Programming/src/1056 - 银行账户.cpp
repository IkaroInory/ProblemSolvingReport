#include <iostream>

using namespace std;

class Account {
private:
    string _accno;
    string _accname;
    float _balance;
public:
    int count;
    float InterestRate;

    Account() : _accno("<id>"), _accname("<name>"), _balance(0) {}
    Account(string accno, string name, float balance) : _accno(accno), _accname(name), _balance(balance) {}

    void Init(string accno, string name, float balance) {
        _accno = accno;
        _accname = name;
        _balance = balance;
    }
    void Deposit(float amount) {
        _balance += amount;
    }
    void Withdraw(float amount) {
        if (_balance >= amount) {
            _balance -= amount;
        }
    }
    float GetBalance() {
        return _balance;
    }
    void Show() {
        cout << _accno << ' ' << _accname << ' ' << _balance << ' ';
    }
    friend void Update(Account& a);
};

void Update(Account& a) {
    a._balance *= 1 + a.InterestRate;
}

int main() {
    double rate;
    int n;
    cin >> rate >> n;
    Account* account = new Account[n];
    for (int i = 0; i < n; i++) {
        string id, name;
        float balance, within, without;
        cin >> id >> name >> balance >> within >> without;
        account[i].Init(id, name, balance);
        account[i].InterestRate = rate;
        account[i].Deposit(within);
        account[i].Show();
        Update(account[i]);
        cout << account[i].GetBalance() << ' ';
        account[i].Withdraw(without);
        cout << account[i].GetBalance() << endl;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += account[i].GetBalance();
    }
    cout << sum << endl;
    return 0;
};