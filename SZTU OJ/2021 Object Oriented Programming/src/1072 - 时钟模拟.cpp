#include <iostream>
#include <cmath>

using namespace std;

class count {
protected:
	int value;
public:
	count() : value(0) {}
	int getValue() {
		return value;
	}
	void setValue(int v) {
		value = v;
	}
	bool increment() {
		value++;
		return false;
	}
};
class rcount :public count {
private:
	int min_value;
	int max_value;
public:
	rcount(int min, int max) :count(), min_value(min), max_value(max) {}
	bool increment() {
		bool flag = false;
		if (value >= min_value && value < max_value) {
			value++;
		}
		if (value >= max_value) {
			value = min_value;
			flag = true;
		}
		return flag;
	}
};
class timer {
private:
	rcount* hour;
	rcount* minute;
	rcount* second;
public:
	timer(int h, int m, int s) {
		hour = new rcount(0, 24);
		minute = new rcount(0, 60);
		second = new rcount(0, 60);
		hour->setValue(h);
		minute->setValue(m);
		second->setValue(s);
	}
	void time(int s) {
		while (s--) {
			bool fs = second->increment();
			bool fm = false;
			if (fs) {
				fm = minute->increment();
			}
			if (fm) {
				hour->increment();
			}
		}
	}
	void print() {
		cout << hour->getValue() << ":" << minute->getValue() << ":" << second->getValue() << endl;
	}
};

int main() {
	int n;
	cin >> n;
	while (n--) {
		int h, m, s, ps;
		cin >> h >> m >> s >> ps;

		timer t(h, m, s);
		t.time(ps);
		t.print();
	}
	return 0;
}