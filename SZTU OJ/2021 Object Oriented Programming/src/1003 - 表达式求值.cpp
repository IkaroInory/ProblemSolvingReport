#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << (a + b > c && b == c) << endl;
    }
    return 0;
}