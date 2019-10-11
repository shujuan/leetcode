class Solution {
    vector<pair<int,int>>dirs = {{1, 0}, {0, 1}};
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int res=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'X' && visited[i][j] == false) {
                    int horizon = i, vertical = j;
                    visited[i][j] = true;
                    dfs(board, visited, horizon, vertical, i, j);
                    if(horizon == i || vertical == j) res++;
                    else return 0;
                }
            }
        }
        return res;
        
    }
    
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int& h, int& v, int x, int y) {
        for(auto dir : dirs) {
            int nx = x+dir.first;
            int ny = y + dir.second;
            if(nx>=0 && nx <board.size() && ny>=0 && ny<board[0].size()&& !visited[nx][ny] && board[nx][ny] == 'X') {
                h |= nx;
                v |= ny;
                visited[nx][ny] = true;
                dfs(board,visited, h,v, nx, ny);
            }
        }
    }
};