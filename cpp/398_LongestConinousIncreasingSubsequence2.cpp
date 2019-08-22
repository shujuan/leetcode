class Solution {
    //vector<pair<int, int>> dirs = {{-1, 0}, {1,0}, {0, 1}, {0,-1}};
    const int dirx[4] = {0, 0, 1, -1};
    const int diry[4] = {1, -1, 0, 0};
    int maxdepth;
    vector<vector<int>>dp;
public:
    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    void dfs(vector<vector<int>>& matrix, int x, int y, int depth){
        if(++depth > dp[x][y]){
            dp[x][y] = depth;
            if(maxdepth < depth)
                maxdepth = depth;
        } else {
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx>=0 && nx < matrix.size() && ny >=0 && ny <matrix[0].size() && matrix[x][y] <matrix[nx][ny]) {
              
                dfs(matrix, nx, ny, dp[x][y]);
            }
        }
        
        
    }
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
        // write your code here
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        dp.resize(m, vector<int>(n, 0));
        maxdepth =0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(dp[i][j] == 0) {
                    dfs(matrix, i, j, 0);
                }
            }
        }
        
        return maxdepth;
    }
};
