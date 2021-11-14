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