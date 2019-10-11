class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},  {-1,0}, {0,1}, {0,-1}};
    
    void DFS(vector<vector<char>>&board, int i, int j, int l, int w){
        if(board[i][j]=='X'||board[i][j]=='1')
            return;
        board[i][j]='1';
        for(int k=0; k<4; k++){
            int ii = dir[k].first;
            int jj = dir[k].second;
            if((i+ii)>=0&&(i+ii)<l&&(j+jj)>=0&&(j+jj)<w){
                DFS(board,i+ii,j+jj,l,w);
            }
        }
    }
    
    
    
    void solve(vector<vector<char>>& board) {
        int l = board.size();
        if(!l) return;
        int w = board[0].size();
        for(int i=0; i<l; i++){
            if(board[i][0] =='O')
                DFS(board, i, 0, l, w);
            if(board[i][w-1] == 'O')
                DFS(board, i, w-1,l,w);
        }
        for(int j=1; j<w-1; j++){
            if(board[0][j] =='O')
                DFS(board, 0, j, l, w);
            if(board[l-1][j] == 'O')
                DFS(board, l-1, j,l,w);
        }
        
        for(int i=0; i<l;i++)
            for(int j=0; j<w; j++){
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        
    }
};