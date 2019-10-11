class Solution {
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        int res =1;
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i=0;i<m; i++) {        
            for(int j=0; j<n; j++) {
                res = max(res, getMaxPath(matrix, i, j, dp));
            }
            
        }
        return res;
    }
    
    int getMaxPath(vector<vector<int>>&matrix, int i, int j, vector<vector<int>>&dp) {
        if(dp[i][j]>0) return dp[i][j];
        int mx=1;
        for(auto dir : dirs) {
            int nx= i+dir.first;
            int ny = j+dir.second;
            if(nx>=0 && nx <matrix.size() && ny>=0 && ny<matrix[0].size() && matrix[i][j] < matrix[nx][ny]) 
            {
                mx = max(mx, 1+getMaxPath(matrix, nx, ny, dp));
            }
        }
        dp[i][j] = mx;
        return mx;
    }
    
   
};