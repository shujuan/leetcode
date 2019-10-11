class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int m = maze.size();
        if(!m) return -1;
        int n = maze[0].size();
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>>q;
        q.push({start[0], start[1]});
        dp[start[0]][start[1]] = 0;
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int x = top.first, y = top.second;
            for(auto dir : dirs) {
                int tmp = dp[x][y];
                int next_x = x+dir.first;
                int next_y = y+dir.second;
                while(next_x>=0 && next_x<m && next_y>=0 && next_y <n && maze[next_x][next_y]== 0) {
                    tmp++;
                    next_x +=dir.first;
                    next_y += dir.second;
                }
                
                next_x -= dir.first;
                next_y -= dir.second;
                if(tmp <dp[next_x][next_y]) {
                    dp[next_x][next_y] = tmp;
                    q.push({next_x, next_y});
                }
            }
            
        }
        
        return dp[destination[0]][destination[1]] == INT_MAX ? -1 : dp[destination[0]][destination[1]];
        
        
        
        
    }
};