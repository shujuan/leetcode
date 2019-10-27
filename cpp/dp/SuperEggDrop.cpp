class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>>dp(K+1, vector<int>(N+1));
        for(int j=1; j<=N; j++){
            dp[1][j] = j;
        }
        
        for(int i=2; i<=K; i++) {
            int s=1;
            for(int j=1; j<=N; j++) {
                dp[i][j] = j;
                if(s<j && dp[i-1][s-1] < dp[i][j-s]) s++;
                dp[i][j] = min(dp[i][j], max(dp[i-1][s-1], dp[i][j-s])+1);
            }
        }
        
        return dp[K][N];
    }
};