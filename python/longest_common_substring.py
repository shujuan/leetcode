class Solution:
    """
    @param A: A string
    @param B: A string
    @return: the length of the longest common substring.
    """
    def longestCommonSubstring(self, A, B):
        # write your code here
        m,n = len(A), len(B)
        maxLen = 0
        for i in range(m):
            for j in range(n):
                length =0
                while i+length < m and j+length < n and A[i+length] == B[j+length]:
                    length +=1 
                    if(length > maxLen):
                        maxLen = length
        
        return maxLen

test = Solution()
A = "ABCD"
B = "CBCE"
res = test.longestCommonSubstring(A,B)
print(res)
