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

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

using namespace std;

class Point {
    double x, y;
public:
    Point();
    Point(const Point& p);
    Point(double x_value, double y_value);
    ~Point();
    double getX();
    double getY();
    void setXY(double x1, double y1) { x = x1; y = y1; }
    void setX(double x_value);
    void setY(double y_value);
    double getDisTo(const Point &p);
};

Point::Point() :x(0), y(0) {
    cout << "Constructor." << endl;
}
Point::Point(const Point& p) { 
    x = p.x;
    y = p.y;
}
Point::Point(double x_value, double y_value) : x(x_value), y(y_value) {
    cout << "Constructor." << endl;
}
Point::~Point(){
    cout << "Distructor." << endl;
}
double Point::getX() { return x; }
double Point::getY() { return y; }
void Point::setX(double x_value) { x = x_value; }
void Point::setY(double y_value) { y = y_value; }
double Point::getDisTo(const Point &p) {
    double dx = x - p.x;
    double dy = y - p.y;
    return sqrt(dx * dx + dy * dy);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Point* ps = new Point[n];
        for (int i = 0; i < n; i++) {
            int tx, ty;
            cin >> tx >> ty;
            ps[i].setXY(tx, ty);
        }
        
        double maxLen = 0;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double temp = ps[i].getDisTo(ps[j]);
                if (temp > maxLen) {
                    maxLen = temp;
                    n1 = i;
                    n2 = j;
                }
            }
        }
        cout << fixed << setprecision(2)
            << "The longeset distance is " << maxLen << ","
            << "between p[" << n1 << "] and p[" << n2 << "]." << endl;
        delete[] ps;
    }
    return 0;
}