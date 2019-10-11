class Solution {
    vector<pair<int,int>>dirs = {{-1,0}, {1,0}, {0, 1}, {0, -1}};
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        int res =-1;
        int m = grid.size();
        if(!m) return res;
        int n = grid[0].size();
        vector<pair<int,int>>houses;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    houses.push_back({i, j});
                }
            }
        }
        vector<vector<int>>dist(m, vector<int>(n, 0));
        vector<vector<int>>reach(m, vector<int>(n, 0));
        for(auto house : houses) {
            queue<pair<int,int>>q;
            q.push(house);
           // cout<<"house:"<<house.first<<" "<<house.second<<"\n";
            vector<vector<bool>>visited(m, vector<bool>(n, false));
            int level =0; 
            while(!q.empty()){
                level++;
                int k = q.size();
                for(int i=0; i<k; i++) {
                    auto top = q.front();
                    q.pop();
                    for(auto dir : dirs) {
                        int nx = top.first + dir.first;
                        int ny = top.second + dir.second;
                        if(nx>=0 && nx<m && ny>=0 && ny <n && grid[nx][ny]==0 && !visited[nx][ny]) {
                          //  cout<<top.first <<" "<< top.second <<nx << " "<<ny<<"\n";
                            visited[nx][ny] = true;
                            reach[nx][ny]++;
                            dist[nx][ny] += level;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0;j<n; j++) {
                //cout <<i<<" " <<j<<" " << grid[i][j] << " " << reach[i][j]<<" "<<dist[i][j] <<" "<<"\n";
                if(grid[i][j]==0 && reach[i][j]==houses.size()){
                    if(res == -1) res = dist[i][j];
                    else res = min(res, dist[i][j]);
                    
                }
            }
        }
        return res;
        
        
    }
};