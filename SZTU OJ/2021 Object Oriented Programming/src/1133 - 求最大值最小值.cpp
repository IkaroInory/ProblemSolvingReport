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

void find(int* num, int n, int& minIndex, int& maxIndex) {
    minIndex = min_element(num, num + n) - num;
    maxIndex = max_element(num, num + n) - num;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* num = new int[n];
        for (int i = 0; i < n; i++) cin >> num[i];

        int minIndex = 0;
        int maxIndex = 0;
        find(num, n, minIndex, maxIndex);
        cout << "min=" << *(num + minIndex) << " "
            << "minindex=" << minIndex << " "
            << endl;
        cout << "max=" << *(num + maxIndex) << " "
            << "maxindex=" << maxIndex << " "
            << endl;
        cout << endl;
    }
    return 0;
}