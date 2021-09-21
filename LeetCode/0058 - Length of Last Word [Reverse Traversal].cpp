class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int p = len - 1;
        int res = 0;
        while (s[p] == ' ') p--;                // Delete trailing space.
        while (p >= 0 && s[p--] != ' ') res++;  // Statistical character.
        return res;
    }
};