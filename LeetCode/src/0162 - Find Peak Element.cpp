//
// vector           #include <vector>
// max_element      #include <algorithm>
//
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};