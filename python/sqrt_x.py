class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
        lf, rt = 1, x
        
        while lf <= rt:
            mid = lf +(rt-lf)//2
            if mid <= x//mid:
                lf = mid+1 
            else:
                rt = mid-1
        return rt

test = Solution()
x = 5
res = test.sqrt(x)
print(res)

