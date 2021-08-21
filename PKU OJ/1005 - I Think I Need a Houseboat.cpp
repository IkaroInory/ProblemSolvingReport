#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        cout << "Property " << i << ": "
            << "This property will begin eroding in year "
            << ceil(3.1415926 * (x * x + y * y) / 100) << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}