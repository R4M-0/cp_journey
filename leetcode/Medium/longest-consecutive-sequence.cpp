class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0|| nums.size()==1) return nums.size();
        set<int> s;
        for (auto x : nums){
                s.insert(x);
        }
        int m=1,curr_m=1;
        for (auto x: s){
            if(s.find(x+1) != s.end()) {curr_m++; m=max(m,curr_m);}
            else curr_m=1;
        }
        return m;
    }
};
