class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char,int> s_map , t_map;
        for (char s_char : s) {
            s_map[s_char]++;
        }
        for (char t_char : t) {
            t_map[t_char]++;
        }
        return(t_map == s_map);
    }
};
