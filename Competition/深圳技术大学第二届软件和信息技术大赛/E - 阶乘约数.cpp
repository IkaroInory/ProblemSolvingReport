#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

bool isprime(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void primefac(int n, unordered_map<int, int>& map) {
    for (int i = 2; i <= n; i++)
        if (n % i == 0)
            if (isprime(i)) {
                map[i]++;
                n /= i;
                i = 1;
            }
}

int main() {
    unordered_map<int, int> map;
    for (int i = 1; i < 100; i++)
        primefac(i, map);
    long long res = 1;
    for (unordered_map<int, int>::iterator cur = map.begin(); cur != map.end(); cur++)
        res *= (1 + cur->second);
    cout << res << endl;
    return 0;
}