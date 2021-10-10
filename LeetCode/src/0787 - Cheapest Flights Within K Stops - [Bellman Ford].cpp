//
// vector   #include <vector>
//
class Solution {
public:
    vector<int> BellmanFord(vector<vector<int>> graph, int pointCount, int originPoint, int maxEdge) {
        vector<int> p;
        vector<int> c;
        for (int i = 0; i < pointCount; i++) {
            if (i == originPoint) {
                p.emplace_back(0);
                c.emplace_back(0);
                continue;
            }
            p.emplace_back(INT_MAX);
            c.emplace_back(INT_MAX);
        }

        for (int i = 0; i < maxEdge; i++) {
            for (int j = 0; j < graph.size(); j++) {
                // graph[j] = [p[i], c[i], edge[j]]
                // c[i] = p[i] + edge[j]

                if (p[graph[j][0]] == INT_MAX) continue;
                if (p[graph[j][0]] + graph[j][2] < c[graph[j][1]])
                    c[graph[j][1]] = p[graph[j][0]] + graph[j][2];
            }
            p = c;
        }

        return c;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int res = BellmanFord(flights, n, src, k + 1)[dst];
        return res != INT_MAX ? res : -1;
    }
};