class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int app = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) app++;
            else {
                if(app > n/3) ans.push_back(nums[i-1]);
                app = 1;
            }
        }

        if(app > n/3) ans.push_back(nums[n-1]);

        return ans;
    }
};
