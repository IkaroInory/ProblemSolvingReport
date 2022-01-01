class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};

        vector<vector<int>> res;
        for (auto cur = original.begin(); cur != original.end(); cur += n)
            res.emplace_back(cur, cur + n);
        return res;
    }
};