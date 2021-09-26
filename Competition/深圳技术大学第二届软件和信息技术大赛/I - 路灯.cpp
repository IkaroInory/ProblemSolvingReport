#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    while (n--) {
        int temp;
        cin >> temp;
        res ^= temp;
    }

    cout << res << endl;
    return 0;
}