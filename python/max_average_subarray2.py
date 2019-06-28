class Solution:
    """
    @param nums: an array with positive and negative numbers
    @param k: an integer
    @return: the maximum average
    """
    def maxAverage(self, nums, k):
        # write your code here
        lf, rt = min(nums), max(nums)
        mid = (lf +rt)/2
        n = len(nums)
        while (rt-lf) >1e-5:
            mid = (lf+rt)/2
            sum = [0]
            for i in range(n):
                sum.append(sum[-1] + nums[i] - mid)
                
            premin = 0
            for i in range(k, n+1):
                if (sum[i]-premin) > 0:
                    lf = mid
                    break
                premin = min(premin, sum[i-k+1])
                
            if lf != mid: 
                rt = mid
        
        return rt

test = Solution()
nums = [1,12,-5,-6, 50, 3]
k = 3
res = test.maxAverage(nums, k)
print(res)
