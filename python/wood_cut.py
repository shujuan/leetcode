class Solution:
    """
    @param L: Given n pieces of wood with length L[i]
    @param k: An integer
    @return: The maximum length of the small pieces
    """
    def woodCut(self, L, k):
        # write your code here
        if not L:
            return 0
        lf, rt = 1, max(L)
        
        while lf <= rt:
            mid = lf + (rt-lf)//2
            cnt =0
            for i in range(len(L)):
                cnt += L[i]//mid
            
            if cnt < k:
                rt = mid-1
            else:
                lf = mid+1 
            
        return rt 
        
L = [232, 124, 456]
k = 7
test = Solution()
res = test.woodCut(L, k)
print(res)

