#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> split(string s, char c) {
        vector<string> ans;
        string cur;
        for (char ch : s) {
            if (ch == c) {
                if (cur != "") {
                    ans.emplace_back(cur);
                    cur.clear();
                }
            }
            else
                cur += ch;
        }
        if (cur != "")
            ans.emplace_back(cur);

        return ans;
    }
    string simplifyPath(string path) {
        vector<string> elements = split(path, '/');
        stack<string> list;
        for (auto s : elements) {
            if (s == ".") continue;
            if (s == "..") {
                if (list.empty()) continue;
                list.pop();
            }
            else
                list.push(s);
        }

        string res = "";
        while (!list.empty()) {
            res = "/" + list.top() + res;
            list.pop();
        }

        return res == "" ? "/" : res;
    }
};