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
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2021%20Object%20Oriented%20Programming
//
//

#include <iostream>

using namespace std;

int main() {
    string jan = "January";
    string feb = "February";
    string mar = "March";
    string apr = "April";
    string may = "May";
    string jun = "June";
    string jul = "July";
    string agu = "Aguest";
    string sep = "September";
    string oct = "October";
    string nov = "November";
    string dec = "December";
    string** p = new string* [12];
    p[0] = &jan;
    p[1] = &feb;
    p[2] = &mar;
    p[3] = &apr;
    p[4] = &may;
    p[5] = &jun;
    p[6] = &jul;
    p[7] = &agu;
    p[8] = &sep;
    p[9] = &oct;
    p[10] = &nov;
    p[11] = &dec;


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 12)
            cout << *p[n - 1];
        else
            cout << "error";
        cout << endl;
    }
    return 0;
}