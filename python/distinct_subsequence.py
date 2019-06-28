class Solution:
    """
    @param S: A string
    @param T: A string
    @return: Count the number of distinct subsequences
    """
    def numDistinct(self, S, T):
        # write your code here
        m,n = len(S), len(T)
        dp =[[0]*(n+1) for _ in range(m+1)]
        for i in range(m+1):
            dp[i][0] = 1 
        
        for j in range(1, n+1):
            for i in range(1, m+1):
                if S[i-1] ==T[j-1]:
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                    
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[m][n] 


test = Solution()
S="rabbbit"
T = "rabbit"

res = test.numDistinct(S,T)
print(res)
