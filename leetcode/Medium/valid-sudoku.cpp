class Solution {
public:
    bool isValid(vector<vector<char>>& board , int x , int y){
        for(int i=0 ; i<9 ; i++){
            if(board[i][y]==board[x][y] && x!=i) return false;
        }
        for(int i=0 ; i<9 ; i++){
            if(board[x][i]==board[x][y] && i!=y) return false;
        }
        pair<int, int> cell{x/3, y/3};
        int start_i=cell.first * 3 , end_i=cell.first * 3 +2 , start_j=cell.second * 3  , end_j=cell.second * 3 + 2 ; 
        for(int i=start_i ; i<=end_i ; i++){
            for(int j=start_j ; j<=end_j ; j++){
                if (board[i][j]==board[x][y] && (x!=i || y!=j)) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if (board[i][j] == '.') continue;
                if (!isValid(board, i, j)) return false;
            }
        }
        return true;
    }
};
