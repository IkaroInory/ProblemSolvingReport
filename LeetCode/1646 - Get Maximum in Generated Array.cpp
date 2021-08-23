//
// vector   #include <vector>
// sort     #include <algorithm>
//
class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums;
        for (int i = 0; i < n + 1; i++) {
            if (i == 0) nums.emplace_back(0);
            if (i == 1) nums.emplace_back(1);
            if (i > 1) {
                if (i % 2) {
                    nums.emplace_back(nums[(i - 1) / 2] + nums[(i + 1) / 2]);
                }
                else {
                    nums.emplace_back(nums[i / 2]);
                }
            }
        }
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[0];
    }
};