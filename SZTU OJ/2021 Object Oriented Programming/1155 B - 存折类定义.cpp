//
//
// Author   IkaroInory
// Date     2021/9/27
//
// All the code of this course and submitted on Online Judge is open source on Github.
// Welcome to reference and verification.
//
// Online Judge
// http://10.11.219.17/JudgeOnline/
// Github Repository
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2020%20Object%20Oriented%20Programming
//
//

#include <iostream>
#include <vector>

using namespace std;

class CAccount {
    private:
        long account;
        string name;
        float balance;

    public:
        CAccount() {
            account = 0;
            name = "<name>";
            balance = 0;
        }
        CAccount(long _account, string _name, float _balance) {
            account = _account;
            name = _name;
            balance = _balance;
            check();
        }

        void check() {
            cout << name << "'s balance is " << balance << endl;
        }
        void deposit(float _b) {
            balance += _b;
            cout << "saving ok!" << endl;
            check();
        }
        void withdraw(float _b) {
            if (_b > balance) {
                cout << "sorry! over limit!" << endl;
                check();
                return;
            }

            balance -= _b;
            cout << "withdraw ok!" << endl;
            check();
        }

};

int main() {
    for (int i = 0; i < 2; i++) {
        long account;
        string name;
        float balance;
        CAccount temp;
        cin >> account >> name >> balance;
        temp = { account, name, balance };
        int _b;
        cin >> _b;
        temp.deposit(_b);
        cin >> _b;
        temp.withdraw(_b);
    }

    return 0;
}