#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
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

int main()
{
    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = { 2 };
    double num = (new Solution())->findMedianSortedArrays(nums1, nums2);
    cout << num << endl;
    return 0;
}