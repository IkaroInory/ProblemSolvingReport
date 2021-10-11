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

#include <iostream>
#include <iomanip>

using namespace std;

class Point {
    double x, y;
public:
    Point();
    Point(double x_value, double y_value);
    double getX();
    double getY();
    void setX(double x_value);
    void setY(double y_value);
    double distanceToAnotherPoint(Point p);
};

Point::Point() :x(0), y(0) {}
Point::Point(double x_value, double y_value) : x(x_value), y(y_value) {}
double Point::getX() { return x; }
double Point::getY() { return y; }
void Point::setX(double x_value) { x = x_value; }
void Point::setY(double y_value) { y = y_value; }
double Point::distanceToAnotherPoint(Point p) {
    double dx = x - p.getX();
    double dy = y - p.getY();
    return sqrt(dx * dx + dy * dy);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        double tx1, ty1, tx2, ty2;
        cin >> tx1 >> ty1 >> tx2 >> ty2;
        Point p1(tx1, ty1), p2(tx2, ty2);
        
        cout << fixed << setprecision(2)
            << "Distance of Point"
            << "(" << p1.getX() << "," << p1.getY() << ")"
            << " to Point"
            << "(" << p2.getX() << "," << p2.getY() << ")"
            << " is " << p1.distanceToAnotherPoint(p2) << endl;
    }
    return 0;
}