class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vow = 0,curr_vow = 0;
        int l=0,r=0;
        while(r<s.size()){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u') curr_vow++;
            if(r-l+1 >= k){
                max_vow = max(max_vow,curr_vow);
                if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u')curr_vow--;
                l++;
            }
            r++;
        }
        return max_vow;
    }
};
