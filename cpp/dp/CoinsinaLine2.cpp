class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        //write your code here
        int n = values.size();
        if(n<3) return true;
        //dp[i]表示从i到end的最大值
        vector<int>dp(n+1, 0);
        dp[n-1]=values[n-1];
        dp[n-2] = values[n-2]+values[n-1];
        dp[n-3] = values[n-3] +values[n-2];
        for(int i=n-4; i>=0; i--) {
            dp[i] = max(values[i]+min(dp[i+2], dp[i+3]), values[i]+values[i+1]+min(dp[i+3], dp[i+4]));
        }
        
        int sum=0;
        for(int i=0; i<n; i++) {
            sum += values[i];
        }
        return dp[0] > sum-dp[0];
    }
    
    

};