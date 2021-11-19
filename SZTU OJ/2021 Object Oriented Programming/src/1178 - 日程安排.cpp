#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class date {
protected:
	int year;
	int month;
	int day;
public:
	date(int y, int m, int d) :year(y), month(m), day(d) {}
};
class time {
protected:
	int hour;
	int minute;
	int second;
public:
	time(int h, int m, int s) :hour(h), minute(m), second(s) {}
};
class schedule :public date, public time {
private:
	int id;
public:
	schedule(int year, int month, int day, int hour, int minute, int second, int id) :
		date(year, month, day), time(hour, minute, second), id(id) {}
	friend bool before(const schedule& s1, const schedule& s2);
	int getId() {
		return id;
	}
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
	int getHour() {
		return hour;
	}
	int getMinute() {
		return minute;
	}
	int getSecond() {
		return second;
	}
};
bool before(const schedule& s1, const schedule& s2) {
	if (s1.year < s2.year) return true;
	else if (s1.year == s2.year) {
		if (s1.month < s2.month) return true;
		else if (s1.month == s2.month) {
			if (s1.day < s2.day) return true;
			else if (s1.day == s2.day) {
				if (s1.hour < s2.hour) return true;
				else if (s1.hour == s2.hour) {
					if (s1.minute < s2.minute) return true;
					else if (s1.minute == s2.minute) {
						if (s1.second < s2.second) return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	int id;
	vector<schedule> list;
	while (cin >> id && id != 0) {
		int y, m, d, h, min, s;
		cin >> y >> m >> d >> h >> min >> s;
		schedule temp(y, m, d, h, min, s, id);
		list.push_back(temp);
	}

	int n = list.size();
	sort(list.begin(), list.end(), before);

	schedule p = list[0];
	cout << "The urgent schedule is No." << p.getId() << ": ";
	printf("%04d/%02d/%02d ", p.getYear(), p.getMonth(), p.getDay());
	printf("%02d:%02d:%02d", p.getHour(), p.getMinute(), p.getSecond());
	return 0;
}