import sys
class Solution:
    """
    @param: A: An integer array
    @param: target: An integer
    @return: An integer
    """
    def MinAdjustmentCost(self, A, target):
        # write your code here
        m = len(A)
        dp = [[sys.maxsize]*101 for _ in range(m+1)]
        for j in range(101):
            dp[0][j] = 0 
        
        for i in range(1, m+1):
            for j in range(0, 101):
                for k in range(0, 101):
                    if dp[i-1][k] == sys.maxsize:
                        continue
                    if abs(j-k) <= target and dp[i][j] > dp[i-1][k]+ abs(A[i-1]-j):
                        dp[i][j] = dp[i-1][k] + abs(A[i-1]-j)
                        
        res = min(dp[m])
      
        return res

test = Solution()
A = [1,4,2,3]
target= 1
res = test.MinAdjustmentCost(A, target)
print(res)

