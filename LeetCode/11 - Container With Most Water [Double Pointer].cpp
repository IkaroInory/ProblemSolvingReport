#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/*
* If short moved:
*   (right - left) is smaller, min() is smaller or bigger. The area could bigger,
* If long moved:
*   (right - left) is smaller, min() is constant. The area must be smaller.
*/
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

int main()
{
    vector<vector<int>> height = {
        {1,8,6,2,5,4,8,3,7},
        {1,1},
        {4,3,2,1,4},
        {1,2,1}
    };

    for (int i = 0; i < height.size(); i++) {
        cout << "Input: [" << height[i][0];
        for (int j = 1; j < height[i].size(); j++) cout << "," << height[i][j];
        cout << "]" << endl;
        cout << "Output: " << (new Solution())->maxArea(height[i]) << endl;
    }

    return 0;
}