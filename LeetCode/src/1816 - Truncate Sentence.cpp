class Solution {
public:
    string truncateSentence(string s, int k) {
        int len = s.length();
        int count = 0;
        int end = 0;
        for (int i = 0; i < len && count < k; i++) {
            if (s[i] == ' ') {
                count++;
                if (count == k)
                    end = i;
            }
        }
        return end ? s.substr(0, end) : s;
    }
};