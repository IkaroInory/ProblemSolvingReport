//
// map - #include <map>
//
class Solution {
public:
    map<char, int> roman = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
    };
    int romanToInt(string s) {
        int ans = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            ans += roman[s[i]];
            if (i && roman[s[i - 1]] < roman[s[i]]) {
                ans -= roman[s[i - 1]];
                ans += roman[i] - roman[s[i - 1]];
            }
        }

        return ans;
    }
};