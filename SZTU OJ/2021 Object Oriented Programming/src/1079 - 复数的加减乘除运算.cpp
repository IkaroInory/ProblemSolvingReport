#include <iostream>

using namespace std;

class complex {
	float r, i;
public:
	complex() : complex(0, 0) {}
	complex(float r, float i) : r(r), i(i) {}

	friend complex operator+(complex left, complex right) {
		complex res;
		res.r = left.r + right.r;
		res.i = left.i + right.i;
		return res;
	}
	friend complex operator-(complex left, complex right) {
		complex res;
		res.r = left.r - right.r;
		res.i = left.i - right.i;
		return res;
	}
	friend complex operator*(complex left, complex right) {
		complex res;
		res.r = left.r * right.r - left.i * right.i;
		res.i = left.i * right.r + left.r * right.i;
		return res;
	}
	friend complex operator/(complex left, complex right) {
		float temp = right.r * right.r + right.i * right.i;
		complex res;
		res.r = (left.r * right.r + left.i * right.i) / temp;
		res.i = (left.i * right.r - left.r * right.i) / temp;
		return res;
	}

	void show() {
		cout << "Real=" << r << " " << "Image=" << i << endl;
	}
};

int main() {
	float r1, i1, r2, i2;
	cin >> r1 >> i1
		>> r2 >> i2;
	complex c1(r1, i1), c2(r2, i2);
	(c1 + c2).show();
	(c1 - c2).show();
	(c1 * c2).show();
	return 0;
}