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
#include <algorithm>

using namespace std;

struct date {
    int y;
    int m;
    int d;
    date() {
        y = 1900;
        m = 1;
        d = 1;
    }
    void print() {
        cout << y << "-" << m << "-" << d << endl;
    }
};


int main() {
    int t;
    cin >> t;
    date *temp = new date[t];
    for (int i = 0; i < t; i++) {
        cin >> temp[i].y >> temp[i].m >> temp[i].d;
    }

    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            if (temp[i].y > temp[j].y) {
                date p = temp[i];
                temp[i] = temp[j];
                temp[j] = p;
            }
            else if (temp[i].y == temp[j].y) {
                if (temp[i].m > temp[j].m) {
                    date p = temp[i];
                    temp[i] = temp[j];
                    temp[j] = p;
                }
                else if (temp[i].m == temp[j].m) {
                    if (temp[i].d > temp[j].d) {
                        date p = temp[i];
                        temp[i] = temp[j];
                        temp[j] = p;
                    }
                }
            }
        }
    }
    temp[1].print();

    return 0;
}