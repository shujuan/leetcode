class Solution:
    """
    @param: matrix: an integer matrix
    @return: the coordinate of the left-up and right-down number
    """
    def submatrixSum(self, matrix):
        # write your code here
        
        if not matrix or not matrix[0]:
            return None
        
        m, n = len(matrix), len(matrix[0])
        
        for i in range(m):
            sums=[0]*n 
            for j in range(i, m):
                curSum=0
                indxMap ={0:-1}
                for k in range(n):
                    sums[k] += matrix[j][k]
                    curSum +=sums[k]
                    if curSum in indxMap:
                        return [(i,indxMap[curSum]+1), (j, k)]
                    indxMap[curSum] = k 
        return None

test = Solution()
matrix=[[1,5,7],[3,7,-8],[4,-8,9]]
res = test.submatrixSum(matrix)
print(res)
