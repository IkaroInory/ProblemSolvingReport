class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int len = nums.size();
        for (int num : nums) {
            map[num]++;
        }
        vector<int> ans;
        for (const auto& element : map) {
            if (element.second == 1) {
                ans.emplace_back(element.first);
            }
        }
        return ans;
    }
};