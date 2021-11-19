#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class shape {
public:
    virtual double area() = 0;
};
class circle : public shape {
    double r;
public:
    circle(double r) : r(r) {}

    double area() {
        return acos(-1) * r * r;
    }
};
class square : public shape {
    double a;
public:
    square(double a) : a(a) {}

    double area() {
        return a * a;
    }
};
class rectangle : public shape {
    double a, b;
public:
    rectangle(double a, double b) : a(a), b(b) {}

    double area() {
        return a * b;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        double r, c, a, b;
        cin >> r >> c >> a >> b;

        shape* temp = new circle(r);
        cout << fixed << setprecision(2);
        cout << temp->area() << endl;
        temp = new square(c);
        cout << temp->area() << endl;
        temp = new rectangle(a, b);
        cout << temp->area() << endl;

        delete temp;
    }
    return 0;
}