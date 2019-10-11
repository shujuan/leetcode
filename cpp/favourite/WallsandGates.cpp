class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<pair<int,int>> dir = {{0,-1}, {0,1}, {1,0},{-1,0}};
        int m = rooms.size();
        if(!m) return;
        int n = rooms[0].size();
        queue<int> q;
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) {
                if(rooms[i][j] == 0) {
                    q.push(i*n+j);
                }
            }
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            int x = t/n, y = t%n;
            for (auto d : dir) {
                int nx = x+d.first, ny = y+d.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && rooms[nx][ny] >rooms[x][y]+1) 
                {
                    rooms[nx][ny] = rooms[x][y]+1;
                    q.push(nx*n + ny);
                    
                }
            }
        }
        
    }
};