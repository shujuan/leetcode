class Solution:
    """
    @param s1: A string
    @param s2: A string
    @param s3: A string
    @return: Determine whether s3 is formed by interleaving of s1 and s2
    """
    def isInterleave(self, s1, s2, s3):
        # write your code here
        l,m,n= len(s1), len(s2), len(s3)
        if l+m != n:
            return False
        dp = [[False]*(m+1) for _ in range(l+1)]
        dp[0][0] = True
        for i in range(1,l+1):
            if s1[i-1]==s3[i-1]:
                dp[i][0] = True
                
        for j in range(1,m+1):
            if s2[j-1] ==s3[j-1]:
                dp[0][j] = True
        
        for i in range(1,l+1):
            for j in range(1,m+1):
                if (s1[i-1]==s3[i+j-1] and dp[i-1][j]) or (s2[j-1] == s3[i+j-1] and dp[i][j-1]):
                    dp[i][j] = True
        
        return dp[l][m]


test = Solution()
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"
res = test.isInterleave(s1,s2,s3)
print(res)

