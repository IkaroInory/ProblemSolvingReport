//
// vector   #include <vector>
//
class Solution {
public:
    vector<int> twoSum(vector<int> numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int temp = numbers[left] + numbers[right];
            if (temp == target) return { left + 1,right + 1 };
            if (temp > target) right--;
            else left++;
        }
        return {};
    }
};