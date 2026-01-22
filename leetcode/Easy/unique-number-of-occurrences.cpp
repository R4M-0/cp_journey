class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0; i<arr.size();i++){
            m[arr[i]]++;
        }
        unordered_set<int> d;
        for (const auto& pair : m) {
            d.insert(pair.second);
        }
        return(d.size() == m.size());
        
    }
};

