#include <iostream>
#include <sstream>
#include <vector>

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        string rev = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            rev += words[i];
            if (i != 0) rev += " ";
        }

        return rev;
    }
};
