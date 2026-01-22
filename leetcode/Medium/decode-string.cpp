class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
	stack<string> result; 
        
        string currentString = ""; 
        int currentNum = 0; 
        
        for (char c : s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            }
            else if (c == '[') {
                counts.push(currentNum);
                result.push(currentString);
                currentNum = 0;
                currentString = "";
            }
            else if (c == ']') {
                int repeatCount = counts.top(); counts.pop();
                string prevString = result.top(); result.pop();
                
                string repeatedString = "";
                for (int i = 0; i < repeatCount; i++) {
                    repeatedString += currentString;
                }
                currentString = prevString + repeatedString;
            }
            else {
                currentString += c;
            }
        }
        
        return currentString;
    }
};
