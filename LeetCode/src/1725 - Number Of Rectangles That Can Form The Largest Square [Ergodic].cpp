class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> k;
        for (auto& p : rectangles)
            k.emplace_back(min(p[0], p[1]));

        sort(k.begin(), k.end(), greater<int>());

        int ans = 0;
        for (auto p : k)
            if (p == k[0]) ans++;
            else break;

        return ans;
    }
};
