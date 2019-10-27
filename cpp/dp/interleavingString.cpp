class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        // write your code here
        int l = s1.size(), m = s2.size(), n= s3.size();
        if(n != l+m) {
            return false;
        }
        
        vector<vector<bool>>dp(l+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1; i<=l; i++) {
            if (s1[i-1]== s3[i-1])
                dp[i][0] = true;
        }
        
        for (int j=1; j<=m; j++) {
            if (s2[j-1] == s3[j-1])
                dp[0][j] = true;
        }
        
        for (int i=1; i<=l; i++){
            for (int j=1; j<=m; j++) {
                if((s1[i-1]==s3[i+j-1] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]))
                    dp[i][j] = true;
            }
        }
        
        return dp[l][m];
     
        
        
    }
};