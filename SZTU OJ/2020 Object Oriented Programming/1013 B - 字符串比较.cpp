//
// All my codes are open source to Github.
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2020%20Object%20Oriented%20Programming
//

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;

        int len1 = s1.length(), len2 = s2.length();
        if (len1 == len2) {
            int t1 = 0;
            int t2 = 0;
            for (int i = 0; i < len1; i++) {
                if (s1[i] > s2[i]) t1++;
                else if (s1[i] < s2[i]) t2++;
            }
            if (t1 > t2) cout << 1 << endl;
            else if (t1 < t2) cout << -1 << endl;
            else cout << 0 << endl;
        }
        else {
            cout << (len1 > len2 ? 1 : -1) << endl;
        }
    }
    return 0;
}