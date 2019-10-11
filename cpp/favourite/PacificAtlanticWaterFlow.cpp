class Solution {
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>>res;
        int m = matrix.size();
        if(!m) return res;
        int n = matrix[0].size();
        
        vector<vector<bool>>atlantic(m, vector<bool>(n, false));
        vector<vector<bool>>pacific(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, n-1);
        }
        
        for(int j=0; j<n; j++) {
            dfs(matrix, pacific, INT_MIN, 0, j);
            dfs(matrix, atlantic, INT_MIN, m-1, j);
        }
        
        for(int i =0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(atlantic[i][j] && pacific[i][j]) {
                    res.push_back({i,j});
                }
            }
        return res;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int pre, int row, int col) {
        if(row <0 || row >= matrix.size() || col <0 || col>=matrix[0].size() || pre > matrix[row][col] || visited[row][col]) return;
        visited[row][col] = true;
        for(auto dir : dirs) {
            int nextX = row + dir.first;
            int nextY = col + dir.second;
            dfs(matrix, visited, matrix[row][col], nextX, nextY);
        }
    }
    
    
    
};