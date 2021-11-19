#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate(int y, int m, int d) :year(y), month(m), day(d) {}
	bool check() {
		int hd[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (isLeap())
			hd[2]++;
		if (day <= hd[month] && day > 0)
			return true;
		else
			return false;
	}
	bool isLeap() {
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	void print() {
		cout << year << "年" << month << "月" << day << "日";
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
};
class COldID
{
protected:
	string p_id15, p_name; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldID(string name, CDate b, string id15) :p_id15(id15), p_name(name), birthday(b) {}
	bool check0() {
		string m = to_string(birthday.getMonth()).length() == 1 ? "0" + to_string(birthday.getMonth()) : to_string(birthday.getMonth());
		string d = to_string(birthday.getDay()).length() == 1 ? "0" + to_string(birthday.getDay()) : to_string(birthday.getDay());
		string tmp = to_string(birthday.getYear()).substr(2, 2) + m + d;
		return tmp == p_id15.substr(6, 6);
	}
	virtual void print() {}
	string update() {
		string str = p_id15.substr(0, 6);
		str += "19";
		str += p_id15.substr(6, 9);
		int temp = 0;
		int list[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
		for (int i = 0; i < 17; i++) {
			temp += (str[i] - '0') * list[i];
		}
		char cl[] = { '1','0','X','9','8','7','6','5','4','3','2' };
		str += cl[temp % 11];
		return str;
	}
};
class CNewID :public COldID {
private:
	string p_id18;
	CDate issueday;
	int validyear;
public:
	CNewID(string name, CDate b, string id15, string id18, CDate d, int vy) :COldID(name, b, id15), p_id18(id18), issueday(d), validyear(vy) {}
	bool check() {
		int list[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
		int temp = 0;
		if (p_id18.length() != 18) return false;

		if (birthday.check() == false) return false;
		if (issueday.check() == false) return false;
		if (check0() == false) return false;

		if (issueday.getYear() + validyear < 2021) return false;
		else if (issueday.getYear() == 2021) {
			if (issueday.getMonth() < 11) return false;
			else if (issueday.getMonth() == 11) {
				if (issueday.getDay() < 8) return false;
			}
		}


		if (update() != p_id18) return false;

		for (int i = 0; i < 17; i++) {
			if (!(p_id18[i] >= '0' && p_id18[i] <= '9')) return false;
			temp += (p_id18[i] - '0') * list[i];
		}
		char cl[] = { '1','0','X','9','8','7','6','5','4','3','2' };
		if (cl[temp % 11] == p_id18[17])
			return true;
		else
			return false;
	}
	void print() {
		cout << p_id18 << " ";
		issueday.print();
		cout << " ";
		if (validyear >= 100)
			cout << "长期" << endl;
		else
			cout << validyear << "年" << endl;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		string name;
		int y, m, d;
		string id15, id18;
		int iy, im, id;
		int v;
		cin >> name >> y >> m >> d >> id15 >> id18 >> iy >> im >> id >> v;
		CDate birth(y, m, d);
		CDate idate(iy, im, id);
		CNewID temp(name, birth, id15, id18, idate, v);
		cout << name << endl;
		if (temp.check()) {
			temp.print();
		}
		else cout << "illegal id" << endl;
	}
	return 0;
}