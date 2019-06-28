from collections import deque

class Solution:
    """
    @param nums: A list of integers.
    @param k: An integer
    @return: The maximum number inside the window at each moving.
    """
    
    def pushin(self, dq, num):
        while len(dq)!=0 and dq[-1] <num:
            dq.pop()
        dq.append(num)
        
    def popout(self, dq, num):
        if(dq[0] == num):
            dq.popleft()
    
    def maxSlidingWindow(self, nums, k):
        # write your code here
        if not nums or not k:
            return []
        dq = deque([])
        for i in range(k-1):
            self.pushin(dq, nums[i])
        res = []
        for i in range (k-1, len(nums)) :
            self.pushin(dq, nums[i])
            res.append(dq[0])
            self.popout(dq, nums[i-k+1])
            
        return res

test = Solution()
nums = [1,2,7,7,8]
k = 3

res = test.maxSlidingWindow(nums,k)
print(res)
