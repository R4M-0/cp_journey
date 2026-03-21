class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string>& queens) {
        int n = queens.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int col1 = queens[i].find('Q');
                int col2 = queens[j].find('Q');

                if(col1 == col2 || abs(col1 - col2) == abs(i - j))
                    return false;
            }
        }
        return true;
    }
    void permut(vector<string>& queens, int idx) {
        int n = queens.size();
        if(idx == n){
            if(isValid(queens)) ans.push_back(queens);
            return;
        }
        for(int i = idx; i < n; i++){
            swap(queens[idx], queens[i]);
            permut(queens, idx + 1);
            swap(queens[idx], queens[i]);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens;
        for(int i = 0; i < n; i++){
            string s(n, '.');   
            s[i] = 'Q';
            queens.push_back(s);
        }
        permut(queens, 0); 
        return ans;
    }
};
