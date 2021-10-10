//
// vector   #include <vector>
//
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    // ans = edge(0, i) + edge(i, end);
    void dfs(vector<vector<int>> graph, int begin, int end) {
        if (begin == end) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = 0; i < graph[begin].size(); i++) {
            temp.emplace_back(graph[begin][i]);
            dfs(graph, graph[begin][i], end);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        temp.emplace_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};