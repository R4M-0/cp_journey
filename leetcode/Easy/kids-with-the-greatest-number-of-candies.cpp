class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> s(candies.size()); 
        int maxCandies = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++) {
            s[i] = (candies[i] + extraCandies >= maxCandies);
        }
        return s;
    }
};
