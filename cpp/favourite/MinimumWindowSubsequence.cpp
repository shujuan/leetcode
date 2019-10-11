class Solution {
public:
    string minWindow(string S, string T) {
        int m = T.size(), n = S.size();
        // 前i个数相匹配的起点
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0)); 
        int minLen = n+1, start=0;
        for(int j=0; j<=n; j++){
            dp[0][j] = j+1;
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(T[i-1] ==S[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        
        for(int j=1; j<=n; j++) {
            if(dp[m][j] !=0 && minLen>(j-dp[m][j]+1)) {
                minLen = j-dp[m][j]+1;
                start = dp[m][j]-1;
            }
        }
        return minLen==(n+1)? "" : S.substr(start, minLen);
    }
};