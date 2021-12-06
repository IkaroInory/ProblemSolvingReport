class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rlen = ransomNote.length();
        int mlen = magazine.length();
        if (rlen > mlen) return false;

        vector<int> map(26);
        for (int i = 0; i < mlen; i++)
            map[magazine[i] - 'a']++;
        for (int i = 0; i < rlen; i++)
            map[ransomNote[i] - 'a']--;
        sort(map.begin(), map.end());

        return map[0] >= 0;
    }
};