class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int countE = 0;   
        int countD = 0;   
        int countN = 0;   
        int countAE = 0;  

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') countD++;
            if (s[i] == 'e' || s[i] == 'E') countE++;
            if (isdigit(s[i])) {
                if (countE) countAE++;
                else countN++;
            }
            
            if ((s[i] == '+' || s[i] == '-') && i != 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) 
                return false;
            
            else if (isalpha(s[i]) && (s[i] != 'e' && s[i] != 'E')) 
                return false;
            
            else if (countD > 1 || countE > 1) 
                return false;
            
            else if (s[i] == '.' && countE) 
                return false;
            
            else if ((i == 0 || i == n - 1) && (s[i] == 'e' || s[i] == 'E')) 
                return false;
            
            else if (i == 0 && i == n - 1 && s[i] == '.') 
                return false;
           
            else if ((s[i] == 'e' || s[i] == 'E') && !countN) 
                return false;
        }
        
        if ((countE && !countAE) || !countN) return false;
        return true;
    }
};
