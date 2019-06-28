class Solution:
    """
    @param nums: An array of non-negative integers.
    @return: The maximum amount of money you can rob tonight
    """
    def houseRobber2(self, nums):
        # write your code here
        if not nums:
            return 0
        n = len(nums)
        
        if n==1:
            return nums[0]
        
        return max(self.getMax(0, n-1, nums), self.getMax(1,n, nums))
    
    def getMax(self, start, end, nums):
        n = end-start
        dp = [0 for _ in range(n+1)]
        dp[1] = nums[start]
        for i in range(2, n+1):
            dp[i] = max(nums[start+i-1]+dp[i-2], dp[i-1])
        return dp[n]

test = Solution()
nums=[2,3,2,3]
res = test.houseRobber2(nums)
print(res)

