/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
    vector<pair<int, int>>dirs ={{1,2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    bool inBound(vector<vector<bool>>& grid, int x, int y) {
        return x>=0 && x<grid.size() && y>=0 && y<grid[0].size();
    }
    
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        queue<pair<int, int>>q;
        q.push({source.x, source.y});
        int level =0;
        int m =grid.size();
        if(!m) return -1;
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        visited[source.x][source.y] = true;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto top = q.front();
                q.pop();
                if(top.first == destination.x && top.second == destination.y) return level;
              
                for(auto dir : dirs) {
                    int x = top.first + dir.first;
                    int y = top.second + dir.second;
                    if(inBound(grid, x, y) && !visited[x][y] && !grid[x][y]) {
                        q.push({x, y});
                        visited[x][y] = true;
                        if(x == destination.x && y == destination.y) return level+1;
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};
