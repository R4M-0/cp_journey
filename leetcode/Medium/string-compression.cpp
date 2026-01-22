class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 1;
        string s = "";

        for (int i = 0; i < chars.size() - 1; i++) {
            if (chars[i] == chars[i + 1]) {
                j++;
            } else {
                s += chars[i];  
                if (j > 1) {
                    s += to_string(j); 
                }
                j = 1; 
            }
        }

        s += chars.back();
        if (j > 1) {
            s += to_string(j);
        }
        chars.assign(s.begin(), s.end());

        return s.length();
    }
};
