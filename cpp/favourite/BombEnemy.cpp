class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res =0;
        int m = grid.size();
        if(!m) return res;
        int n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '0') {
                    int cnt = 0; 
                    int nx= i, ny = j;
                    while(nx >=0 && grid[nx][j] != 'W') {
                        if(grid[nx--][j] == 'E') cnt++;
                    }
                    while(ny >=0 && grid[i][ny] != 'W') {
                        if(grid[i][ny--] == 'E') cnt++;
                    }
                    nx= i, ny = j;
                    while(nx <m && grid[nx][j] != 'W') {
                        if(grid[nx++][j] == 'E') cnt++;
                    }
                    while(ny <n && grid[i][ny] != 'W') {
                        if(grid[i][ny++] == 'E') cnt++;
                    }
                    if(cnt > res) res = cnt;
                    
                }
            }
        }
        return res;
    }
};