#include <iostream>

using namespace std;

class point {
    int x, y;
public:
    point() : point(0, 0) {}
    point(int x, int y) : x(x), y(y) {}
    
    bool operator==(point p) {
        return x == p.x && y == p.y;
    }

    int getx() {
        return x;
    }
    int gety() {
        return y;
    }
};
class rectangle {
    point lu, rd;
public:
    rectangle(point lu, point rd) : lu(lu), rd(rd) {}

    bool operator>(point p) {
        bool x = p.getx() >= lu.getx() && p.getx() <= rd.getx();
        bool y = p.gety() >= rd.gety() && p.gety() <= lu.gety();
        return x && y;
    }
    bool operator>(rectangle r) {
        return *this > r.lu && * this > r.rd;
    }
    bool operator==(rectangle r) {
        return lu == r.lu && rd == r.rd;
    }
    bool operator*(rectangle r) {
        for (int y = rd.gety(); y <= lu.gety(); y++)
            for (int x = lu.getx(); x <= rd.getx(); x++)
                if (r > point(x, y))
                    return true;
        return false;
    }
    friend ostream& operator<<(ostream& cout, rectangle& r);

    operator int() {
        return (rd.getx() - lu.getx()) * (lu.gety() - rd.gety());
    }
};

ostream& operator<<(ostream& cout, rectangle& r) {
    cout << r.lu.getx() << " " << r.lu.gety() << " "
        << r.rd.getx() << " " << r.rd.gety();
    
    return cout;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2
            >> x3 >> y3 >> x4 >> y4;
        point p11(x1, y1), p12(x2, y2), p21(x3, y3), p22(x4, y4);
        rectangle r1(p11, p12), r2(p21, p22);

        cout << "矩形1:" << r1 << " " << (int)r1 << endl
            << "矩形2:" << r2 << " " << (int)r2 << endl;

        if (r1 == r2)
            cout << "矩形1和矩形2相等" << endl;
        else if (r2 > r1)
            cout << "矩形2包含矩形1" << endl;
        else if (r1 > r2)
            cout << "矩形1包含矩形2" << endl;
        else if (r1 * r2)
            cout << "矩形1和矩形2相交" << endl;
        else
            cout << "矩形1和矩形2不相交" << endl;
        cout << endl;
    }
    return 0;
}