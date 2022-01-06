#include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, top = 0;
        for (auto c : s) {
            if (c == '(') top++;
            else if (c == ')') top--;
            depth = max(top, depth);
        }

        return depth;
    }
};