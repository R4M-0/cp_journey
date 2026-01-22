class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l=0,r=0, i;
        for(i=1 ; i<nums.size() ; i++){
            r+=nums[i];
        }
        if(l==r) return 0;
        i=0;
        while(l!=r && i<nums.size()-1){
            l+=nums[i];
            r-=nums[i+1];
            i++;
        }

        if (l==r) return i;

        return -1;
    }
};
