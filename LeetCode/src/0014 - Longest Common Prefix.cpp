#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        int len = INT_MAX;
        for (int i = 0; i < size; i++)
            len = min(len, (int)strs[i].length());

        string res = "";
        for (int i =  1; i <= len; i++) {
            string temp = strs[0].substr(0, i);
            bool isbreak = false;
            for (int j = 1; j < size; j++) {
                if (temp != strs[j].substr(0, i)) {
                    isbreak = true;
                    break;
                }
            }
            if (isbreak)
                break;
            else
                res = temp;
        }
        return res;
    }
};