class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, zeroCount = 0, maxLen = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) zeroCount++;
            while (zeroCount > 1) {
                if (nums[l] == 0) zeroCount--;
                l++;
            }
            maxLen = max(maxLen, r - l);
            r++;
        }
        return maxLen;
    }
};
