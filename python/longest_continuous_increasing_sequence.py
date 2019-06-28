class Solution:
    """
    @param A: An array of Integer
    @return: an integer
    """
    def longestIncreasingContinuousSubsequence(self, A):
        # write your code here
        if not A:
            return 0
        maxL, maxR = 1,1 
        res = 1 
        for i in range(1,len(A)):
            if A[i-1] < A[i]:
                maxL +=1 
                maxR = 1 
            else:
                maxL = 1 
                maxR +=1 
            res = max(res, maxR, maxL)
        return res
A = [5,4,2,1,3]
test = Solution()
res = test.longestIncreasingContinuousSubsequence(A)
print(res) 
