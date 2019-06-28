class Solution:
    """
    @param nums: A list of integer
    @return: An integer, maximum coins
    """
    def maxCoins(self, nums):
        # write your code here
        if not nums:
            return 0
            
        nums = [1,*nums, 1]
        n = len(nums)
        dp = [[0]*(n) for _ in range(n)]
        
        for l in range(1, n-1):
            for i in range(1, n-l):
                j = i+l-1
                for k in range(i, j+1):
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1])
                    
        return dp[1][n-2]

nums=[4,1,5,10]
test = Solution()
res = test.maxCoins(nums)
print(res)
