#include <iostream>
#include <iomanip>

using namespace std;

class point {
protected:
	double x;
	double y;
public:
	point() :point(0, 0) {}
	point(double x, double y) : x(x), y(y) {}

	void printPoint() {
		cout << "(" << x << "," << y << ")";
	}
};
class circle : public point {
protected:
	double r;
public:
	circle(double x, double y, double r) : point(x, y), r(r) {}

	void print() {
		cout << "Circle:";
		printPoint();
		cout << "," << r << endl;
	}
	void getArea() {
		printf("Area:%.2f\n", 3.14 * r * r);
	}
};
class cylinder : public circle {
protected:
	double h;
public:
	cylinder(double x, double y, double r, double h) : circle(x, y, r), h(h) {}
	void print() {
		cout << "Cylinder:";
		printPoint();
		cout << "," << r << "," << h << endl;
	}
	void getVolume() {
		printf("Volume:%.2f\n", 3.14 * r * r * h);
	}
};

int main() {
	double x, y, r, h;
	cin >> x >> y >> r;

	circle c(x, y, r);
	c.print();
	c.getArea();

	cin >> x >> y >> r >> h;

	cylinder ch(x, y, r, h);
	ch.print();
	ch.getVolume();

	return 0;
}