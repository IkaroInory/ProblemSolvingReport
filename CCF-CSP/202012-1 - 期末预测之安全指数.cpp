#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p = 0;
    for (int i = 0; i < n; i++) {
        int w, score;
        cin >> w >> score;
        p += w * score;
    }

    cout << max(0, p);
    return 0;
}