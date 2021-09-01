#include <iostream>
#include <cmath>

using namespace std;

int A[605][605], S[605][605];
int main()
{
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tl[] = { 0,0 }, br[] = { 0,0 };
            tl[0] = max(1, i - r);
            tl[1] = max(1, j - r);
            br[0] = min(n, i + r);
            br[1] = min(n, j + r);
            int temp = S[br[0]][br[1]] - S[br[0]][tl[1] - 1] - S[tl[0] - 1][br[1]] + S[tl[0] - 1][tl[1] - 1];
            if (temp <= (br[0] - tl[0] + 1) * (br[1] - tl[1] + 1) * t) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}