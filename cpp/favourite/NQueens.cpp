class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string row(n, '.');
        vector<string>board(n, row);
        vector<vector<string>>res;
        
        dfs(board, 0, res, n);
       
        return res;
    }
    
    void dfs(vector<string>&board, int row,  vector<vector<string>>&res, int n) {
        if(row == n){
            res.push_back(board);
            return;
        }
        
        for(int j=0; j<n; j++) {
            if(isValid(board, row, j, n)){
                board[row][j] = 'Q';
                dfs(board, row+1, res, n);
                board[row][j] = '.';
            }
        }
   
    }
    
    bool isValid(vector<string>&board, int row, int col, int n) {
        for(int i=0; i<=row; i++) {
            if(board[i][col] == 'Q') return false;
        }
        // for(int i=0; i<=col; i++) {
        //     if(board[row][i] == 'Q') return false;
        // }
        
        for(int i=row, j=col;i>=0 && j>=0; i--,j--) {
            if(board[i][j] == 'Q') return false;
        }
        
        for(int i=row, j=col;i>=0 && j<n; i--,j++) {
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
        
        
    }
};