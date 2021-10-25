#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double xx, double yy) : x(xx), y(yy) {}
    friend double Distance(Point& a, Point& b);
};
double Distance(Point& a, Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1), p2(x2, y2);
        cout << (int)Distance(p1, p2) << endl;
    }
    return 0;
};