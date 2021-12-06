class Solution {
public:
    int sum(vector<int> nums) {
        int ans = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
            ans += nums[i];
        return ans;
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        while (k--) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        return sum(nums);
    }
};