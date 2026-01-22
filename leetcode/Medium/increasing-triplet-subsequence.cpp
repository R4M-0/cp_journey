class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX;
        int j = INT_MAX;
        for(int n : nums){
            if(i >=n){
                i = n;
            } else if(j >= n){
                j = n;
            } else{
                return true;
            }
        }
        return false;

    }
};
