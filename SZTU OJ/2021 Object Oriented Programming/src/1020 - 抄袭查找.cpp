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
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2021%20Object%20Oriented%20Programming
//
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct paper {
    int id;
    string key[3];
    paper() {
        id = 0;
        key[0] = "";
        key[1] = "";
        key[2] = "";
    }
};

int comp(const paper& p1, const paper& p2) {
    for (int num = 0; num < 3; num++) {
        int len = min(p1.key[num].length(), p2.key[num].length());

        int equal = 0;
        for (int c = 0; c < len; c++) {
            if (p1.key[num][c] == p2.key[num][c]) equal++;
        }

        if (equal >= 0.9 * len) return num + 1;
    }

    return 0;
}

int main() {
    int t;
    cin >> t;
    vector<paper> p(t);
    for (int i = 0; i < t; i++) {
        cin >> p[i].id
            >> p[i].key[0] >> p[i].key[1] >> p[i].key[2];
    }

    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            int num = comp(p[i], p[j]);
            if (num != 0) {
                cout << p[i].id << ' ' << p[j].id << ' ' << num << endl;
            }
        }
    }
    return 0;
}