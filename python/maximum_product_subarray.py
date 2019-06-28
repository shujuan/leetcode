class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """
    def maxProduct(self, nums):
        # write your code here
        if not nums:
            return 0
        mini, maxi, res = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            if nums[i]>0 :
                maxi = max(maxi*nums[i], nums[i])
                mini = min(mini*nums[i], nums[i])
            else:
                tmp = maxi
                maxi = max(mini*nums[i], nums[i])
                mini = min(tmp*nums[i], nums[i])
            res = max(res, maxi)
        return res

test = Solution()
nums = [2,3,-1,4]
res = test.maxProduct(nums)
print(res)
