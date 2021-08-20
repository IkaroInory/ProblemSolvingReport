#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    string intToRoman(int num) {
        int value[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        string c[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

        // Greedy Algorithm
        string ans = "";
        for (int i = 0;i < 13;i++) {
            while (num >= value[i]) {
                num -= value[i];
                ans += c[i];
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> x = {
        3,
        4,
        9,
        58,
        1994
    };

    for (int i = 0; i < x.size(); i++) {
        cout << "Input: " << x[i] << endl;
        cout << "Output: " << (new Solution())->intToRoman(x[i]) << endl;
    }
    return 0;
}