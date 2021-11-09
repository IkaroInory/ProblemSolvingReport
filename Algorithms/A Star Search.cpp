class graph {
    unordered_map<string, unordered_map<string, int>> edge;
public:
    void addPoint(string p) {
        if (edge.find(p) == edge.end())
            this->edge[p] = {};
    }
    void addEdge(string p1, string p2, int weight) {
        if (edge.find(p1) != edge.end() && edge.find(p2) != edge.end()) {
            this->edge[p1].emplace(p2, weight);
            this->edge[p2].emplace(p1, weight);
        }
    }
    unordered_map<string, int> getEdge(string p) {
        return edge[p];
    }
    int getWeight(string from,string to) {
        if (edge[from].find(to) != edge[from].end()) {
            return edge[from][to];
        }
        return -1;
    }
    bool hasPoint(string p) {
        return edge.find(p) != edge.end();
    }

    unordered_map<string, int> operator[](string p) {
        return this->edge[p];
    }
};

bool cmp(pair<string, int> left, pair<string, int> right) {
    return left.second < right.second;
}
pair<double, vector<string>> aStar(graph g, unordered_map<string, int> h, string begin, string end) {
    // f(n) = g(n) + h(n)
    if (!(g.hasPoint(begin) && g.hasPoint(end))) return { -1,{} };
    if (begin == end) return { 0,{begin, end} };

    int len = 0;
    vector<string> road;
    road.emplace_back(begin);

    string cur = begin;
    while (cur != end) {
        vector<pair<string, int>> f;
        unordered_map<string, int> temp = g[cur];
        auto ib = temp.begin();
        auto ie = temp.end();
        while (ib != ie) {
            // f.emplace_back(ib->first, ib->second + h[ib->first]);
            f.emplace_back(ib->first, len + ib->second + h[ib->first]);
            ib++;
        }
        sort(f.begin(), f.end(), cmp);
        len += g.getWeight(cur, f[0].first);
        road.emplace_back(f[0].first);
        cur = f[0].first;
    }
    return { len,road };
}