class Solution {
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(!m) return 0;
        int n = heightMap[0].size();
        int res =0;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<m; i++) {
            pq.push({heightMap[i][0], i*n});
            visited[i][0] = true;
            pq.push({heightMap[i][n-1], i*n+n-1});
            visited[i][n-1] = true;
        }
        
        for(int j=1; j<n-1; j++){
            pq.push({heightMap[0][j], j});
            visited[0][j] = true;
            pq.push({heightMap[m-1][j], (m-1)*n+j});
            visited[m-1][j] = true;
        }
        int H = INT_MIN;
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int curH = t.first;
            int x = t.second/n;
            int y = t.second%n;
            H = max(curH, H);
            res += H-curH;
            
            for(auto dir : dirs) {
                int nx = x+dir.first;
                int ny = y + dir.second;
                if(nx >=0 && nx <m && ny>=0 && ny<n && !visited[nx][ny]){
                    pq.push({heightMap[nx][ny], nx*n+ny});
                    visited[nx][ny] = true;
                        
                }
            }
        }
        
        return res;
        
      
        
    }
};