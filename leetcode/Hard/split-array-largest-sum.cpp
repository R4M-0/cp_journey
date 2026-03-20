class Solution {
public:
    bool canFit(vector<int>& nums,int mid, int k){
        int cnt=1;
        int sum=0;
        for(int num: nums){
            if((sum+num)>mid){
                cnt++;
                sum=num;
            }
            else sum+=num;
        }
        return cnt <= k ;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        int mi=-1 , ma=0;
        for(auto & x : nums){
            mi=max(mi,x);
            ma+=x;
        }
        int sol=0;
        while(mi <= ma){
            int mid = mi +(ma-mi)/2;
            if(canFit(nums,mid,k)){
                sol=mid;
                ma=mid-1;
            }
            else mi=mid+1;
        }
        return sol;
    }
};
