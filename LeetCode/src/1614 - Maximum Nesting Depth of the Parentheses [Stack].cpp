#include <stack>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        stack<char> list;
        for (auto c : s) {
            if (c == '(') list.push(c);
            else if (c == ')') list.pop();
            depth = max((int)list.size(), depth);
        }

        return depth;
    }
};