class Solution:
    """
    @param s1: A string
    @param s2: Another string
    @return: whether s2 is a scrambled string of s1
    """
    def isScramble(self, s1, s2):
        # write your code here
        if s1==s2:
            return True
     
        if len(s1) != len(s2):
            return False
        n = len(s1)
        dp = [[[False]*(n+1) for _ in range(n+1)] for _ in range(n+1)]
        for lenth in range(1, n+1):
            for i in range(1, n-lenth+2):
                for j in range(1, n-lenth+2):
                    if lenth == 1:
                        if s1[i-1] == s2[j-1]:
                            dp[i][j][lenth] = True
                        else:
                            dp[i][j][lenth] = False
                      
                    for k in range(1, lenth):
                        if (dp[i+k][j+k][lenth-k] and dp[i][j][k]) or (dp[i+k][j][lenth-k] and dp[i][j+lenth-k][k]):
                            dp[i][j][lenth] = True
        
        return dp[1][1][n]

s1= "great"
s2 = "rgeat"
test = Solution()
res = test.isScramble(s1, s2)
print(res)
