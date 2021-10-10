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
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2021%20Object%20Oriented%20Programming
//
//

#include <iostream>
#include <vector>

using namespace std;

class student {
    public:
        string name;
        int id;
        string sex;
        string college;
        long long phone;
};

int main() {
    int n;
    cin >> n;
    vector<student> list(n);
    for (int i = 0; i < n; i++) {
        string name;
        int id;
        string sex;
        string college;
        long long phone;
        cin >> name >> id >> sex >> college >> phone;
        list[i] = { name, id, sex, college, phone };
    }

    for (int i = 0; i < n; i++) cout << list[i].name << endl;
    return 0;
}