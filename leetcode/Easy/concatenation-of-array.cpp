class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n= nums.size();
        vector<int> nums2;
        for(int i=0 ; i<2*n ; i++){
            nums2.push_back(nums[i % n]);
        }
        return nums2;
    }
};
