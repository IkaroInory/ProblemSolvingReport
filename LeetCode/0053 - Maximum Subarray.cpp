//
// vector       #include <vector>
// sort         #include <algorithm>
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = nums.size();
        for (int i = 1; i < count; i++) {
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
        }

        sort(nums.begin(), nums.end(), greater<int>());

        return nums[0];
    }
};