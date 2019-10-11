class Solution {
    vector<pair<int,int>>dirs = {{-1,0}, {-1,-1}, {-1,1}, {0, 1}, {0, -1}, {1,1}, {1,0}, {1, -1}};
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(!m) return;
        int n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int cnt =0;
                for(auto dir : dirs) {
                    int nx = i+dir.first;
                    int ny = j+dir.second;
                    if(nx>=0 && nx <m && ny >=0 && ny <n && (board[nx][ny]&1)){
                        cnt++;
                    }
                }
                if(board[i][j] && (cnt ==2 || cnt==3)) {
                    board[i][j] = 3;
                }
                
                if(!board[i][j] && (cnt==3)) {
                    board[i][j]=2;
                }
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] >>=1;
            }
        }
        
    }
};