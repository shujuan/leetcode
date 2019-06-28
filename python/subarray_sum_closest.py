import sys
class Solution:
    """
    @param: nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def subarraySumClosest(self, nums):
        # write your code here
        preSum = [(0,-1)]
        for i, num in enumerate(nums):
            preSum.append((preSum[-1][0]+num, i))
        
        preSum.sort()
        
        mindiff, res = sys.maxsize, []
        for i in range(1, len(preSum)):
            if mindiff > abs(preSum[i][0]-preSum[i-1][0]) :
                start = min(preSum[i][1], preSum[i-1][1])+1 
                end = max(preSum[i][1], preSum[i-1][1])
                res = [start,end]
                mindiff = abs(preSum[i][0]-preSum[i-1][0])
                
        return res

nums=[-3,1,1,-3,5]
test = Solution()
res = test.subarraySumClosest(nums)
print(res)
