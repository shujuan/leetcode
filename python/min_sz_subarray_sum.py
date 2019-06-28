class Solution:
    """
    @param nums: an array of integers
    @param s: An integer
    @return: an integer representing the minimum size of subarray
    """
    def minimumSize(self, nums, s):
        # write your code here
        lf = 0
        rt = 0
        sum = 0
        n = len(nums)
        res = n+1
        while rt < n:
            while sum < s and rt < n:
                sum +=nums[rt]
                rt +=1
            
            if sum < s:
                break
            
            while sum >= s and lf <=rt:
                sum -=nums[lf]
                lf +=1
            
            res = min(res, rt-lf+1)
            
        if res==n+1 :
           return -1
        
        return res


test = Solution()
nums = [2,3,1,2,4,3]
s = 7
res = test.minimumSize(nums, s)
print(res)

