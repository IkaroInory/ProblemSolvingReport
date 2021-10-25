#include <iostream>

using namespace std;

class complex {
private:
    double real;
    double imag;
public:
    complex() : real(0), imag(0) {}
    complex(double r, double i) : real(r), imag(i) {}

    friend complex addCom(complex c1, complex c2) {
        complex ans(c1.real + c2.real, c1.imag + c2.imag);
        return ans;
    }
    friend void outCom(complex c) {
        cout << '(' << c.real << ',' << c.imag << ')' << endl;
    }
};

int main() {
    double r, i;
    int n;
    cin >> r >> i >> n;
    complex c(r, i);
    while (n--) {
        char o;
        int rr, ii;
        cin >> o >> rr >> ii;
        complex* cp = o == '+' ? new complex(rr, ii) : new complex(-rr, -ii);
        c = addCom(c, *cp);
        outCom(c);
    }
    return 0;
};