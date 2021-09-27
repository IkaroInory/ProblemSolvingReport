//
//
// Author   IkaroInory
// Date     2021/9/27
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
#include <cmath>

using namespace std;

class point {
    private:
        float x;
        float y;
    public:
        point() {
            x = 0;
            y = 0;
        }
        point(float _x, float _y) {
            x = _x;
            y = _y;
        }
        void setPoint(float _x, float _y) {
            x = _x;
            y = _y;
        }
        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
};

class circle {
    private:
        point o;
        float r;
    public:
        circle(point _o, float _r) {
            o = _o;
            r = _r;
        }
        circle(float _ox, float _oy, float _r) {
            o = { _ox, _oy };
            r = _r;
        }
        void setCenter(float _ox, float _oy) {
            o = { _ox, _oy };
        }
        void setRadius(float _r) {
            r = _r;
        }
        float getArea() {
            return 3.14 * r * r;
        }
        float getLength() {
            return 2 * 3.14 * r;
        }
        string isContain(point _o) {
            float x = o.getX();
            float y = o.getY();
            float _x = _o.getX();
            float _y = _o.getY();
            float l = sqrt((x - _x) * (x - _x) + (y - _y) * (y - _y));
            if (l <= r) return "yes";
            else return "no";
        }
};

int main() {
    float ox, oy, r, x, y;
    cin >> ox >> oy >> r
        >> x >> y;
    point p = { x, y };
    circle c = { {ox, oy}, r };

    cout << c.getArea() << " " << c.getLength() << endl
        << c.isContain(p) << endl;

    return 0;
}