class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        if(n==1)return 0;
        for(int dist=1;dist<n;dist++)
        for(int i=1;i+dist<=n;i++){
            int j=i+dist;
            dp[i][j]=INT_MAX;
            for(int k=i;k<=j;k++){
                dp[i][j]=min(dp[i][j],k+max((k>i?dp[i][k-1]:0),(k<j?dp[k+1][j]:0)));
            }
        }
        return dp[1][n];
    }
};