#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int avg = 0;
        int* p = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            avg += p[i];
        }
        avg /= n;

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (p[i] > avg) ans++;

        cout << ans << endl;
    }
    return 0;
}