class Solution {
public:
    bool closeStrings(string word1, string word2) {
     if(word1==word2) return true;
     if (word1.length()!=word2.length()) return false;
     map<char , int> m1,m2;
     for(int i=0 ; i<word1.length() ;i++){
        m1[word1[i]]++;
        m2[word2[i]]++;
     }
     if (m1==m2) return true;
     vector<int> v1,v2;
     for (const auto &pair : m1) {
        if(m2.find(pair.first)==m2.end()) return false;
        v1.push_back(pair.second);
     }
     for (const auto &pair : m2) {
        if(m1.find(pair.first)==m1.end()) return false;
        v2.push_back(pair.second);
     }
     sort(v1.begin(),v1.end());
     sort(v2.begin(),v2.end());
     return(v1==v2);

    }
};
