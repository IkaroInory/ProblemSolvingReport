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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[3] = { 0 };
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3, greater<int>());
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
    return 0;
}