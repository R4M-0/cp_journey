class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l =0;
        int r=n-1;
        while(l<=r){
            int x = s[l];
            s[l] = s[r];
            s[r] = x;
            l++;
            r--;
        }
        
    }
};
