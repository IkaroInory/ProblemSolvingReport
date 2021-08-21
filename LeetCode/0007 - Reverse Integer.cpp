class Solution {
public:
    int reverse(int x) {
        if (x == 0)return 0;

        bool isNegative = x < 0;

        int abs = 0;
        while (x) {
            if (abs > (pow(2, 31) - 1) / 10 || abs < -pow(2, 31) / 10) return 0;
            abs *= 10;          // Expand capacity.
            abs += x % 10;      // Push and Pop.
            x /= 10;            // Destory.
        }

        return abs;
    }
};