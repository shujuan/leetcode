class Solution {
public:
    /**
     * @param n: An integer
     * @return: An Integer
     */
    int climbStairs2(int n) {
        // write your code here
        vector<int>dp(n+1, 0);
        dp[0] =1;
        dp[1] =1;
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
        
    }
};
