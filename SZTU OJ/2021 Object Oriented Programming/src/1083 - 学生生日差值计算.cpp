#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class date {
	int y, m, d;
	bool isLeap() {
		return ((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0;
	}
	int getDay(int m) {
		int month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (isLeap()) month[2]++;
		return month[m];
	}
public:
	date() : date(0, 0, 0) {}
	date(int y, int m, int d) : y(y), m(m), d(d) {}

	friend date operator++(date& d, int n) {
		if (d.d < d.getDay(d.m)) d.d++;
		else {
			d.d = 1;
			if (d.m < 12) d.m++;
			else {
				d.d = 1;
				d.m = 1;
				d.y++;
			}
		}
		return d;
	}
	friend bool operator==(date left, date right) {
		return left.y == right.y && left.m == right.m && left.d == right.d;
	}
	friend bool operator>(date left, date right) {
		if (left.y < right.y) return true;
		else if (left.y == right.y) {
			if (left.m < right.m) return true;
			else if (left.m == right.m) {
				if (left.d < right.d) return true;
			}
		}
		return false;
	}
	friend bool operator<(date left, date right) {
		if (right.y < left.y) return true;
		else if (right.y == left.y) {
			if (right.m < left.m) return true;
			else if (right.m == left.m) {
				if (right.d < left.d) return true;
			}
		}
		return false;
	}
};

class student {
	string name;
	date birthday;
public:
	student() : student("name", 0, 0, 0) {}
	student(string name, int y, int m, int d) :
		name(name),
		birthday(date(y, m, d)) {}

	int operator-(student right) {
		int res = 0;
		date ld = birthday, rd = right.birthday;
		while (ld > rd) {
			ld++;
			res++;
		}
		while (ld < rd) {
			rd++;
			res++;
		}
		return res;
	}

	string getname() {
		return name;
	}
};

int main() {
	int n;
	cin >> n;
	vector<student> s;
	for (int i = 0; i < n; i++) {
		string name;
		int y, m, d;
		cin >> name >> y >> m >> d;
		s.emplace_back(student(name, y, m, d));
	}

	int ans = 0;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int temp = s[i] - s[j];
			if (temp > ans) {
				ans = temp;
				x = i;
				y = j;
			}
		}
	}

	cout << s[x].getname() << "和" << s[y].getname() << "年龄相差最大，为" << ans << "天。" << endl;
	return 0;
}