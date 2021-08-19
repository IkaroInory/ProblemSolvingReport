#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    int reverse(int x) {
        // Exceptional Case.
        if (x == 0)return 0;

        int abs = 0;
        while (x) {
            // Whether abs is in the range of int.
            if (abs > (pow(2, 31) - 1) / 10 || abs < -pow(2, 31) / 10) return 0;
            abs *= 10;          // Expand capacity.
            abs += x % 10;      // Push and Pop.
            x /= 10;            // Destory.
        }
        return abs;
    }
};

int main()
{
    vector<int> x = {
        123,
        -123,
        120,
        0,
        1534236469,
        -2147483648
    };

    for (int i = 0; i < x.size(); i++) {
        cout << "Input: " << x[i] << endl;
        cout << "Output: " << (new Solution())->reverse(x[i]) << endl;
    }
    return 0;
}