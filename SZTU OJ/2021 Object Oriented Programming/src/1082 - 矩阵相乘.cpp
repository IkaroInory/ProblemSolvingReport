#include <iostream>
#include <vector>

using namespace std;

class matrix {
	int n;
	vector<vector<int>> m;
public:
	matrix() {}
	matrix(vector<vector<int>> m) {
		this->n = m.size();
		this->m = m;
	}

	matrix operator*(matrix right) {
		vector<vector<int>> res;
		for (int i = 0; i < n; i++) {
			vector<int> temp(right.n);
			res.emplace_back(temp);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int p = 0; p < n; p++) {
					res[i][j] += m[i][p] * right.m[p][j];
				}
			}
		}
		return matrix(res);
	}

	void display() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << m[i][j] << " ";
			cout << endl;
		}
	}
};

int main() {
	int c;
	cin >> c;
	vector<matrix> ms;
	int n;
	cin >> n;
	for (int p = 0; p < c; p++) {
		vector<vector<int>> m(n);
		for (int i = 0; i < n; i++) {
			vector<int> temp(n);
			for (int j = 0; j < n; j++)
				cin >> temp[j];
			m[i] = temp;
		}
		ms.emplace_back(matrix(m));
	}

	matrix res(ms[0]);
	for (int i = 1; i < c; i++) {
		res = res * ms[i];
	}
	res.display();
	return 0;
}