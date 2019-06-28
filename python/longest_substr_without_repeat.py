class Solution:
    """
    @param s: a string
    @return: an integer
    """
    def lengthOfLongestSubstring(self, s):
        # write your code here
        n = len(s)
        lf =0
        rt = 0
        res = 0
        last = {}
       
        for rt, c in enumerate(s) :
            if c in last:
                lf = max(last[c]+1, lf)
            res = max(rt - lf + 1, res)
            
            last[c] = rt
             
                
                
        return res


test = Solution()
s = "abcabcbb"
print(test.lengthOfLongestSubstring(s))
