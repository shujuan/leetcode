import sys
class Solution:
    """
    @param A: An integer array
    @return: An integer
    """
    def stoneGame(self, A):
        # write your code here
        if not A: 
            return 0
        n = len(A)
        
        dp= [[sys.maxsize]*n for _ in range(n)]
        
        for i in range(n):
            dp[i][i] = 0
        
        # sums = [0]
        # for i in range(1,n+1):
        #     sums.append(sums[i-1]+A[i-1])
            
        for l in range(1, n):
            for i in range(0, n-l):
                j= i+l 
                for k in range(i, j):
                    if dp[i][j] > dp[i][k]+dp[k+1][j] + sum(A[i:j+1]):
                        dp[i][j] = dp[i][k]+dp[k+1][j] + sum(A[i:j+1])
                        
        return dp[0][n-1]

test = Solution()
A = [3,4,3]
res = test.stoneGame(A)
print(res)

