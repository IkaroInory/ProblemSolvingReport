#include <iostream>

using namespace std;

class fraction {
	int numerator;
	int denominator;
public:
	fraction() : numerator(0), denominator(1) {}
	fraction(int a, int b) : numerator(a), denominator(b) {}

	fraction operator+(fraction r) {
		fraction res;
		res.denominator = this->denominator * r.denominator;
		res.numerator = this->denominator * r.numerator + r.denominator * this->numerator;
		return res;
	}
	fraction operator-(fraction r) {
		fraction res;
		res.denominator = this->denominator * r.denominator;
		res.numerator = r.denominator * this->numerator - this->denominator * r.numerator;
		return res;
	}
	fraction operator*(fraction r) {
		fraction res;
		res.denominator = this->denominator * r.denominator;
		res.numerator = this->numerator * r.numerator;
		return res;
	}
	fraction operator/(fraction r) {
		fraction res;
		res.denominator = this->denominator * r.numerator;
		res.numerator = this->numerator * r.denominator;
		return res;
	}

	void display() {
		cout << "fraction=" << numerator << "/" << denominator << endl;
	}
};

int main() {
	int n1, d1, n2, d2;
	cin >> n1 >> d1 >> n2 >> d2;
	fraction f1(n1, d1), f2(n2, d2);
	(f1 + f2).display();
	(f1 - f2).display();
	(f1 * f2).display();
	(f1 / f2).display();
	return 0;
}