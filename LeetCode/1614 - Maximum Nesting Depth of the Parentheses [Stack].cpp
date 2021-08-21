//
// vector   #include <vector>
//
class Solution {
public:
    int maxDepth(string s) {
        vector<char> stack;
        int length = s.length();
        if (length <= 1) return 0;

        int depth = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] == '(') stack.push_back('C');
            if (s[i] == ')') stack.pop_back();
            depth = stack.size() > depth ? stack.size() : depth;
        }
        return depth;
    }
};