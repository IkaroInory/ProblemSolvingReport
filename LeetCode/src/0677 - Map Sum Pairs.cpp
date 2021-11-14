#include <string>
#include <unordered_map>

using namespace std;

class MapSum {
    unordered_map<string, int> map;
public:
    MapSum() {
        
    }

    void insert(string key, int val) {
        map[key] = val;
    }

    int sum(string prefix) {
        int len = prefix.length();
        int ans = 0;
        for (auto cur = map.begin(), end = map.end(); cur != end; cur++)
            if (cur->first.substr(0, len) == prefix)
                ans += cur->second;

        return ans;
    }
};