class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = right + 1;
        while (left <= right) {
            int mid = left * 0.5 + right * 0.5;
            if (nums[mid] == target) return mid;

            if (nums[mid] < target) left = mid + 1;
            if (nums[mid] > target) {
                right = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};