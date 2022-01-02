class Solution {
public:
    int lastRemaining(int n) {
        int a = 1, d = 1;
        bool isLeft = true;
        while (n != 1) {
            if (isLeft || (!isLeft && n % 2))
                a += d;
            d *= 2;
            n -= ceil(n / 2.0);
            isLeft = !isLeft;
        }
        return a;
    }
};