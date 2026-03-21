class Solution {
public:
    int expand(string& s, int l, int r) {
        int count = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;   
            l--;
            r++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans += expand(s, i, i);     
            ans += expand(s, i, i + 1); 
        }
        return ans;
    }
};
