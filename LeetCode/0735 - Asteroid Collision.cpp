//
// vector - #include <vector>
//
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int i = 0; i < asteroids.size(); i++) {
            if (stack.empty() == true) {
                stack.push_back(asteroids[i]);
                continue;
            }
            if (stack.back() > 0 && asteroids[i] < 0) {
                bool isPush = false;
                while (stack.empty() == false && stack.back() > 0 && asteroids[i] < 0) {
                    if (abs(stack.back()) > abs(asteroids[i])) {
                        isPush = false;
                        break;
                    }
                    else if (abs(stack.back()) < abs(asteroids[i])) {
                        stack.pop_back();
                        isPush = true;
                        // stack.push_back(asteroids[i]);
                    }
                    else if (abs(stack.back()) == abs(asteroids[i])) {
                        stack.pop_back();
                        isPush = false;
                        break;
                    }
                }
                if (isPush == true) {
                    stack.push_back(asteroids[i]);
                }
            }
            else {
                stack.push_back(asteroids[i]);
            }
        }
        return stack;
    }
};