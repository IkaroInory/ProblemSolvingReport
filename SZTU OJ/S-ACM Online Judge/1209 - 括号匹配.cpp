#include <iostream>
#include <vector>

using namespace std;

bool isLeftSymbol(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isRightSymbol(char c) {
    return c == ')' || c == ']' || c == '}';
}

int main() {
    string str;
    cin >> str;

    vector<char> list;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (isLeftSymbol(c) || isRightSymbol(c)) {
            if (isLeftSymbol(c)) {
                list.emplace_back(c);
            }
            else {
                if (list.empty()) {
                    cout << "No" << endl;
                    return 0;
                }
                else {
                    if (c == ')' && *(list.end() - 1) == '(') list.pop_back();
                    else if (c == ']' && *(list.end() - 1) == '[') list.pop_back();
                    else if (c == '}' && *(list.end() - 1) == '{') list.pop_back();
                }
            }
        }
    }

    if (!list.empty())
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}