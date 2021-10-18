#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class equation {
private:
    double a;
    double b;
    double c;

    double getDelta() {
        return b * b - 4 * a * c;
    }
public:
    equation() : a(1), b(1), c(0) {}
    equation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    void set(double _a, double _b, double _c) {
        a = _a;
        b = _b;
        c = _c;
    }
    void printRoot() {
        double delta = getDelta();
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / 2 / a;
            double x2 = (-b - sqrt(delta)) / 2 / a;
            cout << fixed << setprecision(2)
                << "x1=" << x1 << " "
                << "x2=" << x2 << endl;
        }
        else if (delta < 0) {
            delta = -delta;
            double rx = -b / 2 / a;
            double ix = sqrt(delta) / 2 / a;
            if (ix < 0) ix = -ix;

            cout << fixed << setprecision(2)
                << "x1=" << rx << "+" << ix << "i" << " "
                << "x2=" << rx << -ix << "i" << endl;
        }
        else {
            double x = -b / 2 / a;
            cout << fixed << setprecision(2)
                << "x1=x2=" << x << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    while (n--) {
        double a, b, c;
        cin >> a >> b >> c;

        equation f(a, b, c);
        f.printRoot();
    }
    return 0;
}