class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: An integer
     * @return: an integer
     */
    void init(vector<vector<int>>& dist, vector<int>& A) {
        int n = A.size();
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++) {
                int mid = (i+j)/2;
                for(int k = i; k<=j; k++){
                    //dist[i][j]表示从第i个房子到第j个房子，到一个邮局的最短距离。
                   dist[i][j] += abs(A[k-1] - A[mid-1]); 
                }
                
            }
        }
        
    }
     
    int postOffice(vector<int> &A, int k) {
        // write your code here
        int n = A.size();
        if(n<=k) return 0;
        sort(A.begin(), A.end());
        vector<vector<int>> dist(n+1, vector<int>(n+1));
        init(dist, A);
        //dp[i][j]表示i个邮局，几个房子的最短距离。
        vector<vector<int>>dp(k+1, vector<int>(n+1, INT_MAX));
        for(int j=2; j<=n; j++) {
            dp[1][j] = dist[1][j];
        }
        
        
        
        for(int i = 2; i<=k; i++) {
            for(int j=i+1; j<=n; j++) {
                for(int l=i+1; l<j; l++){
                    if(dp[i][j] > dp[i-1][l] + dist[l+1][j]) {
                        dp[i][j] = dp[i-1][l] + dist[l+1][j];
                    }
                }
            }
        }
        
        return dp[k][n];
    }
};