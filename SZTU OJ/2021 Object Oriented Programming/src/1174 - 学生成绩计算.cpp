#include <iostream>
#include <cmath>

using namespace std;

class person {
protected:
	string name;
	int age;
	int em;
	int am = 0;
public:
	person(string name, int age, int em) :name(name), age(age), em(em) {}
	virtual void updateScore() {
	}
	char getMark() {
		if (am >= 85) return 'A';
		else if (am >= 75) return 'B';
		else if (am >= 65) return 'C';
		else if (am >= 60) return 'D';
		else return 'F';
	}
	void display() {
		cout << name << " "
			<< age << " "
			<< getMark() << endl;
	}
};
class cp :public person {
public:
	cp(string name, int age, int em) :person(name, age, em) {}
	void updateScore() {
		am = em;
	}
};
class op :public person {
private:
	int um;
public:
	op(string name, int age, int um, int em) :person(name, age, em), um(um) {}
	void updateScore() {
		am = um * 0.4 + em * 0.6;
	}
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		char type;
		string n;
		int age;
		cin >> type >> n >> age;
		person* p;
		if (type == 'R') {
			int um, em;
			cin >> um >> em;
			p = new op(n, age, um, em);
		}
		else {
			int em;
			cin >> em;
			p = new cp(n, age, em);
		}
		p->updateScore();
		p->display();
	}
	return 0;
}