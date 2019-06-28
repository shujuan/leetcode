class Solution:
    # @param {int} n a party with n people
    # @return {int} the celebrity's label or -1
    def findCelebrity(self, n):
        # Write your code here
        res = 0
        for i in range(1, n):
            if Celebrity.knows(res, i) :
                res = i 
        
        for i in range(n):
            if i != res and Celebrity.knows(res, i) :
                return -1
        
        for i in range(n):
            if i !=res and Celebrity.knows(i, res)==False:
                return -1
                
        return res

test = Solution()
n = 10
res = test.findCelebrity(n)
print(res)

