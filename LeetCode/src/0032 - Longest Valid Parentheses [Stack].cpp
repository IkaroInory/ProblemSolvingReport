//
// vector   #include <vector>
// sort     #include <algorithm>
//
class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.length();
        vector<int> stack;
        vector<int> len;
        if (length <= 1) return 0;

        stack.push_back(0);
        for (int i = 0; i < length; i++) {
            if (s[i] == '(') stack.push_back(-i - 1);
            else
                if (!stack.empty() && *(stack.end() - 1) < 0) {
                    stack.pop_back();
                }
                else {
                    stack.push_back(i + 1);
                }
        }

        if (abs(*stack.begin()) != 1) stack.emplace(stack.begin(), 0);
        if (abs(*(stack.end() - 1)) != length) stack.push_back(length + 1);

        int count = stack.size();
        for (int i = 1; i < count; i++) {
            len.push_back(abs(stack[i]) - abs(stack[i - 1]) - 1);
        }
        sort(len.begin(), len.end(), greater<int>());
        return len[0];
    }
};