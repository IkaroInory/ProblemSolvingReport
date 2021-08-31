class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size % 2 == 0) {
            if (nums[size - 1] == target) return size - 1;
            else nums.pop_back();
        }

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = nums[(left + right) * 0.5];
            if (mid == target) return (left + right) * 0.5;

            if (mid > target) right = (left + right) * 0.5 - 1;
            if (mid < target) left = (left + right) * 0.5 + 1;
        }
        return -1;
    }
};