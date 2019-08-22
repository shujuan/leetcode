class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
     
    struct Point{
        int x, y,dist;
        Point(int x, int y, int d): x(x), y(y), dist(d){}
    };
    
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        int minDist =INT_MAX;
        int m = grid.size();
        // cout << "m=" << m << "\n";
        if(!m) return minDist;
        vector<Point> houses;
        int n = grid[0].size();
        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++) {
                if(grid[i][j] == 1) houses.push_back(Point(i,j,0));
            }
        vector<vector<int>> distance(m, vector<int>(n,0));
        vector<vector<int>> reach(m, vector<int>(n,0));
        vector<pair<int,int>> direction = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        // cout << "houses.size()=" << houses.size() << "\n";
        for (int i=0; i<houses.size(); i++) {
            cout << "houses # " << i << "\n";
            queue<Point> q;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            q.push(houses[i]);
        
            while(!q.empty()) {
                Point top = q.front();
                q.pop();
                int level = top.dist;
                cout << top.x << ","<< top.y<< ": " << top.dist << "\n";
                for(auto d: direction){
                    int nx = top.x + d.first;
                    int ny = top.y + d.second;
                    if (nx >=0 && nx < m && ny >=0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 0) {
                        distance[nx][ny] += level + 1;
                        reach[nx][ny]++;
                        visited[nx][ny] = true;
                        q.push(Point(nx, ny, level+1));
                    }
                }
            }
        }
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                // cout << i << ","<< j<< "-- Reach:" << reach[i][j] << "-- Dist:" << distance[i][j] << "\n";
                if (grid[i][j] == 0 && reach[i][j] == houses.size()) {
                    minDist = min(minDist, distance[i][j]);
                }
            }
            
        return minDist==INT_MAX ? -1 : minDist;
        
        
        
        
        
        
    }
};
