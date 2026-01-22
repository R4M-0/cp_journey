class Solution {
public:
    string removeStars(string s) {
        string s1="";
        for(int i=0; i<s.length()-1; i++){
            if(s[i]!='*' && s[i+1]!='*') s1+=s[i];
            if(s[i]=='*' && s[i+1]=='*') s1.pop_back();
        }
        if (s[s.length()-1]!='*') s1+=s[s.length()-1];
        return(s1);
    }
};
