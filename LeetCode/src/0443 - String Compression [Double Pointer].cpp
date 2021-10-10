//
// vector   #include <vector>
//
class Solution {
public:
    void write(vector<char>& chars, char c, int num) {
        if (c) {
            chars.push_back(c);
            if (num != 1) {
                if (num < 9) {
                    chars.push_back('0' + num);
                    return;
                }
                else {
                    for (int i = 0; num; i++) {
                        chars.insert(chars.end() - i, '0' + num % 10);
                        num /= 10;
                    }
                }
            }
        }
    }
    int compress(vector<char>& chars) {
        char pre = 0;
        int count = 0;
        int size = chars.size();
        for (int i = 0; i < size; i++) {
            if (chars[i] != pre) {
                write(chars, pre, count);

                pre = chars[i];
                count = 1;
            }
            else count++;
        }
        write(chars, pre, count);
        chars.erase(chars.begin(), chars.begin() + size);
        return chars.size();
    }
};