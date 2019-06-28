class Solution:
    """
    @param A: An integers array.
    @return: return any of peek positions.
    """
    def findPeak(self, A):
        # write your code here
        lf, rt= 0, len(A)-1
        
        while lf<rt:
            mid = (lf + rt)//2
            if A[mid] <A[mid+1]:
                lf = mid+1
            else:
                rt = mid
        return rt

test = Solution()
A = [1,2,1,3,4,5]
res = test.findPeak(A)
print(res)
