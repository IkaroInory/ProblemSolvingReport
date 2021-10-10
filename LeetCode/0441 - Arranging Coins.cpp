class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1 + (long)8 * n) - 1) / 2;
    }
};