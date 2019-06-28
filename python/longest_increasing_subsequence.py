class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        # write your code here
        if not nums:
            return 0
        n = len(nums)
        tmp = [1 for _ in range(n)]
        res = 1
        for i in range(1, n):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    tmp[i] = max(tmp[j]+1, tmp[i])
            res = max(tmp[i], res)
        
        return res

test = Solution()
nums = [5,4,1,2,3]
res = test.longestIncreasingSubsequence(nums)
print(res)
