//
// All my codes are open source to Github.
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2020%20Object%20Oriented%20Programming
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        string key;
        cin >> str >> key;
        int strLen = str.length();
        int keyLen = key.length();

        char* pwd = new char[strLen + 1];
        pwd[strLen] = '\0';
        for (int i = 0; i < strLen; i++) {
            if (str[i] >= 'a' && str[i] <= 'z')
                pwd[i] = ((str[i] - 'a') + (key[i % keyLen] - '0')) % 26 + 'a';
            else
                pwd[i] = ((str[i] - 'A') + (key[i % keyLen] - '0')) % 26 + 'A';
        }

        cout << pwd << endl;
    }
    return 0;
}