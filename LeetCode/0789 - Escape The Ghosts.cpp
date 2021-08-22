//
// vector   #include <vector>
//
class Solution {
public:
    int ManhattanDistance(vector<int> target) {
        return abs(target[0]) + abs(target[1]);
    }
    int ManhattanDistance(vector<int> point, vector<int> target) {
        return abs(target[0] - point[0]) + abs(target[1] - point[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int player = ManhattanDistance(target);

        int count = ghosts.size();
        for (int i = 0; i < count; i++) {
            if (player >= ManhattanDistance(ghosts[i], target)) {
                return false;
            }
        }
        return true;
    }
};