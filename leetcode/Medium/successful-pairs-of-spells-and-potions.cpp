class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans;

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1;
            int first = m;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if ((long long)spells[i] * potions[mid] >= success) {
                    first = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            ans.push_back(m - first);
        }

        return ans;
    }
};
