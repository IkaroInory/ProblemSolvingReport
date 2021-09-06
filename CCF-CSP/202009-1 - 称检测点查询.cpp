#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int X, Y;

double length(int x, int y) {
    return sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
}

int main() {
    int n;
    cin >> n >> X >> Y;
    vector<double> len;
    while (n--) {
        int x, y;
        cin >> x >> y;
        len.emplace_back(length(x, y));
    }
    auto temp = min_element(len.begin(), len.end());
    cout << temp - len.begin() + 1 << endl;
    *temp = INT16_MAX;
    temp = min_element(len.begin(), len.end());
    cout << temp - len.begin() + 1 << endl;
    *temp = INT16_MAX;
    temp = min_element(len.begin(), len.end());
    cout << temp - len.begin() + 1 << endl;
    *temp = INT16_MAX;
    return 0;
}