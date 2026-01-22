class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        
        for (int asteroid : asteroids) {
            while (!stack.empty() && stack.top() > 0 && asteroid < 0) {
                if (abs(stack.top()) == abs(asteroid)) {
                    stack.pop();  
                    asteroid = 0; 
                } else if (abs(stack.top()) > abs(asteroid)) {
                    asteroid = 0;
                } else {
                    stack.pop(); 
                }
            }
            
            if (asteroid != 0) {
                stack.push(asteroid);
            }
        }
        vector<int> result;
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
