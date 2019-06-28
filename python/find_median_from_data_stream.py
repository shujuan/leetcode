
import heapq


class Solution:
    """
    @param nums: A list of integers
    @return: the median of numbers
    """
    def medianII(self, nums):
        # write your code here
        res =[]
        if not nums:
            return res 
            
        self.smallq = []
        self.largeq = []
        
        cnt = 0 
        for i in range(len(nums)):
            heapq.heappush(self.smallq, -nums[i])
            if cnt%2==0 :
                if len(self.largeq)==0:
                    res.append(-self.smallq[0])
                    cnt +=1 
                    continue
                if -self.smallq[0] > self.largeq[0]:
                    heapq.heappush(self.largeq, - heapq.heappop(self.smallq))
                  
                    heapq.heappush(self.smallq, - heapq.heappop(self.largeq))
                   
            else:
             
                heapq.heappush(self.largeq, -heapq.heappop(self.smallq))
                
            
            cnt +=1 
            res.append(-self.smallq[0])
            
        return res
        

test = Solution()
nums = [1,2,3,4,5]
res = test.medianII(nums)
print(res)

