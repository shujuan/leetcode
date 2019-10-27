class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        vector<int>dp(m+1, 0);
        for(int i=0; i<A.size(); i++) {
            for(int j=m; j>=A[i]; j--) {
                int cnt = 1;
                while(j >= cnt*A[i]) {
                    dp[j] = max(dp[j], dp[j-cnt*A[i]] + cnt*V[i]);
                    cnt++;
                }
            }
        }
        
        return dp[m];
    }
};