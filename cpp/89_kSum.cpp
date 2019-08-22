class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        int n = A.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));
        for(int i=0; i<=n; i++) {
            dp[i][0][0] = 1;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=k; j++) {
                for(int l=1; l<=target; l++){
                    if(A[i-1] <= l) {
                        dp[i][j][l] = dp[i-1][j][l]+dp[i-1][j-1][l-A[i-1]];
                    } else {
                        dp[i][j][l] = dp[i-1][j][l];
                    }
                }
            }
        }
        
        return dp[n][k][target];

    }
};
