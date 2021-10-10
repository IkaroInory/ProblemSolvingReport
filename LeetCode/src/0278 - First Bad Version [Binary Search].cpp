// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left * 0.5 + right * 0.5;
            if (isBadVersion(mid) == false) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};