class Solution {
public:
    string modifyString(string s) {
        vector<char> list = { 'a','b','c' };

        while (s.find('?') != string::npos) {
            int i = s.find('?');

            auto left = i - 1 >= 0 ? find(list.begin(), list.end(), s[i - 1]) : list.end();
            auto right = i + 1 < s.length() ? find(list.begin(), list.end(), s[i + 1]) : list.end();
            if (left == list.end() && right == list.end())
                s[i] = list[0];
            else if (left != list.end() && right != list.end() && left != right)
                s[i] = list[3 - (left - list.begin() + right - list.begin())];
            else
                s[i] = list[((left != list.end() ? left - list.begin() : right - list.begin()) + 1) % 3];
        }

        return s;
    }
};