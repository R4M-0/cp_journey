class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0;
        int start = 0; 

        for (int end = 0; end < s.length(); end++) {
            char current = s[end];
            if (lastSeen.find(current) != lastSeen.end() && lastSeen[current] >= start) {
                start = lastSeen[current] + 1;
            }
            lastSeen[current] = end;

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
