class Solution:
    """
    @param matrix: a matrix of 0 and 1
    @return: an integer
    """
    def maxSquare(self, matrix):
        # write your code here
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp=[[0]*n for i in range(m)]
        res = 0
        for i in range(m):
            for j in range(n):
                if i==0 or j==0:
                    dp[i][j] = matrix[i][j]
                elif matrix[i][j]==1 :
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) +1 
                
                res = max(res, dp[i][j])
            
        return res*res

test = Solution() 
matrix = [[1,0,1,0,0], [1,0,1,1,1], [1,1,1,1,1], [1,0,0,1,0]]

res = test.maxSquare(matrix)
print(res)
