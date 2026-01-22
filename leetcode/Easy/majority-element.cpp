class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        unordered_map<int , int> m;
        int n =nums.size();
        for (int key: nums){
            m[key]++;
            if(m[key]>n/2) return key;
        }
        return 0;
    }
};
