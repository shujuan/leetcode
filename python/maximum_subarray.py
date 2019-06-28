import sys
class Solution:
    """
    @param nums: A list of integers
    @return: A integer indicate the sum of max subarray
    """
    def maxSubArray(self, nums):
        # write your code here
        if not nums:
            return 0
        
        sums = [0]
        res = -sys.maxsize -1 
        for i in range(1, len(nums)+1):
            sums.append(max(sums[i-1],0) + nums[i-1])
            res = max(res, sums[i])
        return res
            
nums = [-2, 2, -3, 4, -1, 2,1,-5, 3]
test = Solution()
res = test.maxSubArray(nums)
print(res)

