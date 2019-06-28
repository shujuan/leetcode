class Solution:
    """
    @param S: A list of integers
    @return: An integer
    """
    def triangleCount(self, S):
        # write your code here
        S.sort()
        res = 0
        for i in range(2,len(S)):
            k = 0
            j = i-1
            while k < j:
                if S[k] + S[j] > S[i]:
                    res += j-k
                    j -= 1
                else :
                    k +=1
        
        return res


test = Solution()
S =[3,4,6,7]
res = test.triangleCount(S)
print(res)

