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
pair<int, vector<string>> aStar(graph g, unordered_map<string, int> h, string begin, string end) {
    // f(n) = g(n) + h(n)
    if (!(g.hasPoint(begin) && g.hasPoint(end))) return { -1, {} };
    if (begin == end) return { 0, {begin, end} };

    int len = 0;
    vector<string> road;
    road.emplace_back(begin);

    string cur = begin;
    while (cur != end) {
        vector<pair<string, int>> f;
        unordered_map<string, int> temp = g[cur];

        for (auto begin = temp.begin(), end = temp.end(); begin != end; begin++)
            if (find(road.begin(), road.end(), begin->first) == road.end())
                f.emplace_back(begin->first, len + begin->second + h[begin->first]);

        sort(f.begin(), f.end(), cmp);
        len += g.getWeight(cur, f[0].first);
        road.emplace_back(f[0].first);
        cur = f[0].first;
    }
    return { len,road };
}