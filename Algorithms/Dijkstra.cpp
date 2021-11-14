class graph {
    unordered_map<string, unordered_map<string, int>> edge;
public:

    void addPoint(string p) {
        if (edge.find(p) == edge.end())
            this->edge[p] = {};
    }
    void addUndirectedEdge(string p1, string p2, int weight) {
        if (edge.find(p1) != edge.end() && edge.find(p2) != edge.end()) {
            this->edge[p1].emplace(p2, weight);
            this->edge[p2].emplace(p1, weight);
        }
    }
    void addDirectedEdge(string p1, string p2, int weight) {
        if (edge.find(p1) != edge.end() && edge.find(p2) != edge.end())
            this->edge[p1].emplace(p2, weight);
    }

    unordered_map<string, int> getEdge(string p) {
        return edge[p];
    }
    int getWeight(string from, string to) {
        if (edge[from].find(to) != edge[from].end()) {
            return edge[from][to];
        }
        return -1;
    }
    int getPointCount() {
        return edge.size();
    }

    bool hasPoint(string p) {
        return edge.find(p) != edge.end();
    }

    unordered_map<string, int> operator[](string p) {
        return this->edge[p];
    }

    auto begin() {
        return edge.begin();
    }
    auto end() {
        return edge.end();
    }
};

bool cmp(pair<string, int> left, pair<string, int> right) {
    return left.second < right.second;
}
pair<unordered_map<string, int>, unordered_map<string, vector<string>>> dijkstra(graph g, string beginPoint) {
    if (!(g.hasPoint(beginPoint))) return { {}, {} };

    int pointCount = g.getPointCount();
    int finished = 0;
    unordered_map<string, bool> isVisit;
    unordered_map<string, int> len;
    unordered_map<string, string> parent;
    for (auto begin = g.begin(), end = g.end(); begin != end; begin++) {
        isVisit[begin->first] = false;
        len[begin->first] = INT32_MAX;
        parent[begin->first] = "null";
    }

    string cur = beginPoint;
    isVisit[cur] = true;
    len[cur] = 0;
    parent[cur] = "main";
    finished++;
    while (finished < pointCount) {
        vector<pair<string, int>> f;
        unordered_map<string, int> temp = g[cur];

        for (auto begin = temp.begin(), end = temp.end(); begin != end; begin++) {
            if (isVisit[begin->first] == true) continue;

            string last = parent[begin->first];
            parent[begin->first] = cur;
            
            if (len[parent[begin->first]] + begin->second < len[begin->first])
                len[begin->first] = len[parent[begin->first]] + begin->second;
            else
                parent[begin->first] = last;
        }

        for (auto begin = len.begin(), end = len.end(); begin != end; begin++) {
            if (isVisit[begin->first] == true) continue;

            f.emplace_back(begin->first, begin->second);
        }

        sort(f.begin(), f.end(), cmp);
        isVisit[f[0].first] = true;
        finished++;
        cur = f[0].first;
    }

    unordered_map<string, vector<string>> path;
    for (auto begin = g.begin(), end = g.end(); begin != end; begin++) {
        if (begin->first == beginPoint) continue;

        vector<string> temp;
        temp.emplace_back(begin->first);
        string cur = parent[begin->first];
        while (cur != beginPoint) {
            temp.emplace_back(cur);
            cur = parent[cur];
        }
        temp.emplace_back(beginPoint);
        reverse(temp.begin(), temp.end());
        path[begin->first] = temp;
    }

    return{ len, path };
}