#include <iostream>
#include <cmath>

using namespace std;

class p2 {
protected:
	double x, y;
public:
	p2(double x, double y) : x(x), y(y) {}
	double getDistance(p2 p) {
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
};
class p3 :public p2 {
protected:
	double z;
public:
	p3(double x, double y, double z) : p2(x, y), z(z) {}
	double getDistance(p3 p) {
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
	}
};


int main() {
	p2 o2(0, 0);
	int x21, y21;
	cin >> x21 >> y21;
	p2 p21(x21, y21);
	cout << p21.getDistance(o2) << endl;

	p3 o3(0, 0, 0);
	int x31, y31, z31, x32, y32, z32;
	cin >> x31 >> y31 >> z31 >> x32 >> y32 >> z32;
	p3 p31(x31, y31, z31), p32(x32, y32, z32);
	cout << p31.getDistance(o3) << endl;
	cout << p32.getDistance(o3) << endl;
	p21 = p32;
	cout << p21.getDistance(o2) << endl;
	return 0;
}