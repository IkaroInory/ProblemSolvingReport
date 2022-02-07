class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> list;

        for (auto p : nums)
            list[p]++;

        int ans = 0;

        for (auto p : list)
            if (p.second == 1)
                ans += p.first;
        return ans;
    }
};
