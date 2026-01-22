class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int operations = 0;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& entry : freq) {
            int num = entry.first;
            int complement = k - num;

            if (num == complement) {
                operations += freq[num] / 2; 
            }
            else if (freq.find(complement) != freq.end()) {
                int pairs = min(freq[num], freq[complement]);
                operations += pairs;
                freq[num] -= pairs;
                freq[complement] -= pairs;
            }
        }

        return operations;
    }
};

