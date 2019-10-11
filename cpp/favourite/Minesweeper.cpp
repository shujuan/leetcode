class Solution {
    vector<pair<int,int>>dirs = {{-1,0}, {-1, -1}, {-1,1}, {0,1},{0,-1}, {1,0}, {1, 1}, {1, -1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
    
        if(board[x][y] == 'M'){
                
                board[x][y] = 'X';
                return board;
        }
        if(board[x][y] != 'E' ) return board;

        int cnt = 0;
        for(auto dir : dirs) {
            int nx = x+dir.first;
            int ny = y + dir.second;
            if(nx>=0 && nx<board.size() && ny>=0 && ny <board[0].size() && ( board[nx][ny] =='M')){
                //q.push({nx, ny});
                if(board[nx][ny] == 'M')cnt++;
            }
        }

        if(cnt) board[x][y] = '0'+cnt;
        else board[x][y]='B';

        if(board[x][y] == 'B') {
            for(auto dir : dirs) {
                int nx = x+dir.first;
                int ny = y + dir.second;
                if(nx>=0 && nx<board.size() && ny>=0 && ny <board[0].size() && (board[nx][ny] == 'E' )){
                      vector<int>next= {nx, ny};
                      updateBoard(board, next);

                }
            }
        }
            
            
       
        
        return board;
       
    }
};