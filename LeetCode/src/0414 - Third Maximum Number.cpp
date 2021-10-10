//
// vector   #include <vector>
// sort     #include <algorithm>
//
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if (nums.size() < 3) {
            return nums[0];
        }
        else {
            return nums[2];
        }
    }
};