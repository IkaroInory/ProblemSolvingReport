//
//
// Author   IkaroInory
// Date     2021/10/11
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class CFraction {
private:
    int fz, fm;
public:
    CFraction(int fz_val, int fm_val);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD();
    void print();
};

CFraction::CFraction(int fz_val, int fm_val) : fz(fz_val), fm(fm_val) {}
CFraction CFraction::add(const CFraction& r) {
    int rfz, rfm;
    rfm = fm * r.fm;
    rfz = fz * r.fm + r.fz * fm;
    int g = gcd(rfm, rfz);
    rfm = rfm / g;
    rfz = rfz / g;
    return { rfz, rfm };
}
CFraction CFraction::sub(const CFraction& r) {
    int rfz, rfm;
    rfm = fm * r.fm;
    rfz = fz * r.fm - r.fz * fm;
    int g = gcd(rfm, rfz);
    rfm = rfm / g;
    rfz = rfz / g;
    if (rfm < 0) {
        rfz = -rfz;
        rfm = -rfm;
    }
    return { rfz, rfm };
}
CFraction CFraction::mul(const CFraction& r) {
    int rfz, rfm;
    rfz = fz * r.fz;
    rfm = fm * r.fm;
    int g = gcd(rfm, rfz);
    rfm = rfm / g;
    rfz = rfz / g;
    return { rfz, rfm };
}
CFraction CFraction::div(const CFraction& r) {
    int rfz, rfm;
    rfz = fz * r.fm;
    rfm = fm * r.fz;
    int g = gcd(rfm, rfz);
    rfm = rfm / g;
    rfz = rfz / g;
    return { rfz, rfm };
}
int CFraction::getGCD() { return gcd(fm, fz); }
void CFraction::print() { cout << fz << "/" << fm << endl; }


int main() {
    int t;
    cin >> t;
    while (t--) {
        int fz1, fm1, fz2, fm2;
        scanf("%d/%d", &fz1, &fm1);
        scanf("%d/%d", &fz2, &fm2);

        CFraction f1(fz1, fm1), f2(fz2, fm2);
        f1.add(f2).print();
        f1.sub(f2).print();
        f1.mul(f2).print();
        f1.div(f2).print();
        
        cout << endl;
    }
    return 0;
}