class Solution {
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if(!T.size()) return 1;
        int m = S.size(), n = T.size();
        
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for(int i=0; i<=m; i++)
            dp[i][0] = 1;
            
        for(int j=1; j<=n; j++){
            for(int i=1; i<=m; i++){
                if(S[i-1] == T[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
      
    }
};