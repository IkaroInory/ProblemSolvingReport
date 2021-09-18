//
//
// Author   IkaroInory
// Date     2021/9/18
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

using namespace std;

struct p {
    string Name;
    int Terminal;
    int Operator;
    string CardIssures;
    string Validity;
    string CardNumber;
    string Traded;
    double Costs;

    string CardNum() {
        string temp = "";
        int len = CardNumber.length();
        for (int i = 0; i < len; i++) {
            if (i >= 4 && i < 12) temp += '*';
            else temp += CardNumber[i];
        }
        return temp;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        p temp;
        cin >> temp.Name
            >> temp.Terminal
            >> temp.Operator
            >> temp.CardIssures
            >> temp.Validity
            >> temp.CardNumber
            >> temp.Traded
            >> temp.Costs;


        cout << "Name: " << temp.Name << endl;
        printf("Terminal: %05d operator: %02d\n", temp.Terminal, temp.Operator);
        cout << "Card Issuers: " << temp.CardIssures << " Validity: " << temp.Validity << endl;
        cout << "CardNumber: " << temp.CardNum() << endl;
        cout << "Traded: " << temp.Traded << endl;
        printf("Costs: $%.2f\n", temp.Costs);
        cout << endl;
    }
    return 0;
}