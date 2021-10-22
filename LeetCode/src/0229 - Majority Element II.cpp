class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = nums.size();
        unordered_map<int, int> map;
        vector<int> ans;
        for (auto& p : nums) {
            map[p]++;
        }
        for (auto& p : map) {
            if (p.second > count / 3) {
                ans.emplace_back(p.first);
            }
        }
        return ans;
    }
};