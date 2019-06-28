class Solution:
    """
    @param s: input string
    @return: the longest palindromic substring
    """
    def longestPalindrome(self, s):
        # write your code here
        if not s:
            return ""
        n = len(s)
        dp = [[False]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
        res, start=1, 0
        for k in range(2, n+1):
            for i in range(0, n-k+1):
                if s[i] == s[i+k-1]:
                    dp[i][i+k-1] = (i+1==(i+k-1) or dp[i+1][i+k-2])
                if dp[i][i+k-1] and res < k:
                    start = i
                    res = k 
                    
        return s[start:start+res]

test = Solution()
s = "abcdzdcab"
res = test.longestPalindrome(s)
print(res)

