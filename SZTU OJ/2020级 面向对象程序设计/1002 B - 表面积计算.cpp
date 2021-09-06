#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int l, d, h;
        cin >> l >> d >> h;
        
        cout << (l * d + l * h + d * h) * 2 << endl;
    }
    return 0;
}