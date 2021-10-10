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
#include <algorithm>

using namespace std;

class cat {
    private:
        string name;
        float weigth;
    public:
        cat() {
            name = "<name>";
            weigth = 0;
        }
        cat(string _n, float _w) {
            name = _n;
            weigth = _w;
        }
        string getName() {
            return name;
        }
        float getWeigth() {
            return weigth;
        }
};

bool cmp(cat a, cat b) {
    return a.getWeigth() < b.getWeigth();
}

int main() {
    int n;
    cin >> n;
    vector<cat> list(n);
    for (int i = 0; i < n; i++) {
        string _n;
        float _w;
        cin >> _n >> _w;
        list[i] = { _n, _w };
    }

    sort(list.begin(), list.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << list[i].getName() << " ";
    }
    return 0;
}