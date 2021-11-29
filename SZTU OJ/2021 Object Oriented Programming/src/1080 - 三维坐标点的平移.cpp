#include <iostream>

using namespace std;

class point {
	int x, y, z;
public:
	point() : point(0, 0, 0) {}
	point(int x, int y, int z) : x(x), y(y), z(z) {}
	point(point& p) {
		x = p.x;
		y = p.y;
		z = p.z;
	}

	friend point operator++(point& p) {
		p.x++;
		p.y++;
		p.z++;
		return p;
	}
	friend point operator++(point& p, int) {
		point temp(p);
		p.x++;
		p.y++;
		p.z++;
		return temp;
	}
	friend point operator--(point& p) {
		p.x--;
		p.y--;
		p.z--;
		return p;
	}
	friend point operator--(point& p, int) {
		point temp(p);
		p.x--;
		p.y--;
		p.z--;
		return temp;
	}

	void show() {
		cout << "x=" << x << " "
			<< "y=" << y << " "
			<< "z=" << z << endl;
	}
};

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	point p1(x, y, z);

	p1++;
	p1.show();
	p1--;
	point p2 = p1;
	p1++;
	p2.show();
	p1--;
	(++p1).show();
	p1.show();
	p1--;
	p1--;
	p1.show();
	p1++;
	p1.show();
	(--p1).show();
	p1.show();
	return 0;
}