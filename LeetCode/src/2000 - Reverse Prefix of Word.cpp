class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto p = find(word.begin(), word.end(), ch);
        if (p == word.end()) return word;

        auto temp = word.substr(0, p - word.begin() + 1);
        reverse(temp.begin(), temp.end());
        return temp + word.substr(p - word.begin() + 1, word.size() - (p - word.begin() + 1));
    }
};