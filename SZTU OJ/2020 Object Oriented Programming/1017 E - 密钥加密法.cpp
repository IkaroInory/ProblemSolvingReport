//
//
// Author   IkaroInory
// Date     2021/9/13
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