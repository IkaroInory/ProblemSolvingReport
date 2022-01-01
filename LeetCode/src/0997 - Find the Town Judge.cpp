class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        if (n == 1 && size == 0) return 1;

        unordered_map<int, int> trustmap;
        unordered_map<int, int> map;
        for (int i = 0; i < size; i++) {
            map[trust[i][1]]++;
            trustmap[trust[i][0]] = trust[i][1];
        }

        for (auto cur = map.begin(); cur != map.end(); cur++) {
            if (cur->second == n - 1)
                if (trustmap.find(cur->first) == trustmap.end())
                    return cur->first;
        }

        return -1;
    }
};