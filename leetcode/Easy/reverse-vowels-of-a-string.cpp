class Solution {
public:
    string reverseVowels(string s) {
        string k = s;
        reverse(k.begin(), k.end());

        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                while (!isVowel(k[j])) {
                    j++;
                }
                s[i] = k[j];
                j++; 
            }
        }
        return s;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
