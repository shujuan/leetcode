class Solution:
    """
    @param s: A string
    @param k: An integer
    @return: An integer
    """
    def lengthOfLongestSubstringKDistinct(self, s, k):
        # write your code here
        lf, cnt, res = 0, 0, 0
        last = {}
        if k == 0:
            return 0
        for rt,c in enumerate(s) :
            last[c] = last.get(c,0) + 1 
            if last[c] == 1:
                cnt +=1
            while cnt > k:
                last[s[lf]] -= 1
                if last[s[lf]] == 0 :
                    cnt -= 1
                lf +=1
            res = max(res, rt - lf+1 )
            
        return res

test = Solution()

s = "eceba"
k = 3

res = test.lengthOfLongestSubstringKDistinct(s,k)
print(res)

