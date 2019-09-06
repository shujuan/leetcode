class Solution {
    vector<pair<int, int>>dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        queue<int>q;
        vector<bool>visited(n*m, false);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push(i*n+j);
                    visited[i*n +j] = true;
                }
            }
        }
        
        int level =0;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto top = q.front();
                q.pop();
                int x = top/n;
                int y = top%n;
                for(auto dir : dirs) {
                    int nx= x+dir.first;
                    int ny = y+dir.second;
                    
                    if(nx >=0 && nx <m && ny>=0 && ny < n && !visited[nx*n+ny] && grid[nx][ny] ==0) {
                        q.push(nx*n+ny);
                        visited[nx*n+ny] = true;
                        grid[nx][ny] =1;
                    }
                }
            }
            if(q.size()) level++;
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] ==0) return -1;
            }
        }
        
        return level;
        
    }
};
