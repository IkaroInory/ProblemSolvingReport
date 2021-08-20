#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return x;
        if (x == -1) return n % 2 ? -x : x;

        if (n == 0) return 1;
        if (n == -1) {
            if (x > 10e4 || x < -10e4) return 0;
            else return 1 / x;
        }
        if (n == 1) {
            if (x > 10e4 || x < -10e4) return 0;
            else return x;
        }
        if (n > 1) {
            if (n % 2) return myPow(x * x, n / 2) * x;
            else return myPow(x * x, n / 2);
        }
        if (n < -1) {
            if (n % 2) return myPow(x * x, n / 2) / x;
            else return myPow(x * x, n / 2);
        }
        return 0;
    }
};

int main()
{
    vector<double> x = {
        -1.0,
    };
    vector<int> n = {
        2147483647,
    };

    for (int i = 0; i < x.size(); i++) {
        cout << "Input: " << x[i] << endl;
        cout << "Output: " << (new Solution())->myPow(x[i], n[i]) << endl;
    }

    return 0;
}