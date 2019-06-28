class Solution:
    """
    @param nums: an array containing n + 1 integers which is between 1 and n
    @return: the duplicate one
    """
    def findDuplicate(self, nums):
        # write your code here
        n = len(nums)-1
        lf,rt = 1, n
        while lf <=rt:
            mid = (lf+rt)//2
            cnt =0
            for i in range(n+1):
                if nums[i] <= mid:
                    cnt += 1 
            if cnt > mid:
                rt = mid-1
            else:
                lf = mid +1 
        
        return lf 

test = Solution()
nums = [5,5,4,3,2,1]
res = test.findDuplicate(nums)
print(res)
