//
// vector   #include <vector>
// sort     #include <algorithm>
//
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        auto left = people.begin();
        auto right = people.end() - 1;
        int ans = 0;
        while (left <= right) {
            if (*left + *right > limit) {
                right--;
            }
            else {
                left++;
                right--;
            }
            ans++;
        }
        return ans;
    }
};