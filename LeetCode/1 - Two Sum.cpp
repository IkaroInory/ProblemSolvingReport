#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (nums[i] + nums[j] == target)
                    return { i,j };
    }
};

int main()
{
    vector<vector<int>> nums = {
        {2,7,11,15},
        {3,2,4},
        {3,3}
    };
    vector<int> target = { 9,6,6 };

    for (int i = 0; i < nums.size(); i++) {
        vector<int> p = (new Solution())->twoSum(nums[i], target[i]);
        cout << "Simple " << i << ": ";
        for (int j = 0; j < p.size(); j++) cout << p[j] << " ";
        cout << endl;
    }
    return 0;
}