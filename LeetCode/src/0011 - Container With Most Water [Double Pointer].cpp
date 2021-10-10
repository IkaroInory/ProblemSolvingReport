//
// vector - #include <vector>
//

//
// If short moved:
//   (right - left) is smaller, min() is smaller or bigger. The area could bigger,
// If long moved:
//   (right - left) is smaller, min() is constant. The area must be smaller.
//
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            int temp = (right - left) * min(height[left], height[right]);
            area = temp > area ? temp : area;

            if (height[left] > height[right])right--;
            else left++;
        }

        return area;
    }
};