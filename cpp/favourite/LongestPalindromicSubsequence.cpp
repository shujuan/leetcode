class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int len=1; len<=n; len++){
            for(int i =0; i+len<=n; i++) {
                if(len==1) {
                    dp[i][i] = 1;
                    continue;
                }
                int j=i+len-1;
                if(s[i] == s[j]) dp[i][j] = (((j-i)==1) ? 0 :dp[i+1][j-1])+2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
        
    }
};