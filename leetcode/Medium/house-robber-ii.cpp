class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n + 2, 0); 
        vector<int> dp2(n + 2, 0); 
        for (int i = n - 1; i >= 1; i--) {
            dp1[i] = max(nums[i] + dp1[i+2], dp1[i+1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            dp2[i] = max(nums[i] + dp2[i+2], dp2[i+1]);
        }
        return max(dp1[1], dp2[0]);
    }
};
