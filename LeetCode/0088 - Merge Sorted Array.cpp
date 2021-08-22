//
// vector   #include <vector>
//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> x(m + n);
        int p1 = 0, p2 = 0, cur;
        for (int i = 0;i < m + n;i++) {
            if (p1 >= m) {
                cur = nums2[p2++];
            }
            else if (p2 >= n) {
                cur = nums1[p1++];
            }
            else if (nums1[p1] <= nums2[p2]) {
                cur = nums1[p1++];
            }
            else {
                cur = nums2[p2++];
            }
            x[p1 + p2 - 1] = cur;
        }

        for (int i = 0;i < m + n;i++) {
            nums1[i] = x[i];
        }
    }
};