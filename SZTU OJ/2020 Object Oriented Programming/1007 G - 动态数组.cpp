#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--) {
        char type;
        int n;
        cin >> type >> n;

        if (type == 'I') {
            int* p = new int[n];
            int ans = 0;
            for (int i = 0; i < n; i++) {
                cin >> p[i];
                ans += p[i];
            }
            cout << ans / n << endl;
        }
        else if (type == 'C') {
            char* p = new char[n];
            char ans = 0;
            for (int i = 0; i < n; i++) cin >> *(p + i);
            sort(p, p + n, greater<char>());
            cout << *p << endl;
        }
        else if (type == 'F') {
            float* p = new float[n];
            float ans = 0;
            for (int i = 0; i < n; i++) cin >> *(p + i);
            sort(p, p + n);
            cout << *p << endl;
        }
    }
    return 0;
}