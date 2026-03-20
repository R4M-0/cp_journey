class TimeMap {
public:

    unordered_map<string , vector<pair<int , string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int , string>temp = {timestamp , value};
        mp[key].push_back(temp);
    }
    
    string get(string key, int timestamp) {

        if(mp.find(key) == mp.end()) return "";

        auto &temp = mp[key];

        int n = temp.size();
        string ans = "";

        int l = 0;
        int r = n-1;

        while(l <= r){

            int mid = l + (r - l)/2;

            if(temp[mid].first <= timestamp){
                ans = temp[mid].second;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return ans;
        
    }
};

