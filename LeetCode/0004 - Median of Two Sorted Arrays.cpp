class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int c1 = nums1.size();
        int c2 = nums2.size();
        for (int i = 0; i < c2; i++) nums1.push_back(nums2[i]);
        sort(nums1.begin(), nums1.end());

        int size = nums1.size();
        if (size % 2) return nums1[(size - 1) / 2];
        else return (nums1[(size) / 2 - 1] + nums1[(size) / 2]) / 2.0;
    }
};