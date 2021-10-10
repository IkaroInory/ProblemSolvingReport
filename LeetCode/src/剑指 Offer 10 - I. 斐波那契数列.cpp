class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int p[101];
        p[0] = 0;
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            p[i] = (p[i - 1] + p[i - 2]) % 1000000007;
        }
        return p[n] % 1000000007;
    }
};