class Solution {
    vector<pair<int, int>>dirs = {{1, 2},{-1,2}, {2,1}, {-2, 1}};
    
public:
    /**
     * @param grid: a chessboard included 0 and 1
     * @return: the shortest path
     */
    int shortestPath2(vector<vector<bool>> &grid) {
        // write your code here
        int m = grid.size();
        if(!m) return -1;
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        dp[0][0]=0;
        for(int j=1; j<n; j++) {
            for(int i=0; i<m; i++) {
                if(grid[i][j] == false) {
                    for(auto dir : dirs) {
                        int preX = i-dir.first;
                        int preY = j-dir.second;
                        if(preX>=0 && preX <m && preY >=0 && preY <n && dp[preX][preY] != INT_MAX) {
                            dp[i][j] = min(dp[i][j], dp[preX][preY]+1);
                        }
                    }
                }
            }
        }
        
        if(dp[m-1][n-1] != INT_MAX) return dp[m-1][n-1];
        else return -1;
        
    }
};
