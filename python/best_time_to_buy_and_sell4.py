class Solution:
    """
    @param K: An integer
    @param prices: An integer array
    @return: Maximum profit
    """
    def maxProfit(self, K, prices):
        # write your code here
        n = len(prices)
        res =0
        if n<2:
            return res 
            
        if K>=n:
            for i in range(1,n):
                res += max(prices[i]-prices[i-1], 0)
        local = [0]*(K+1)
        glob = [0]*(K+1)
        for i in range(1, n):
            diff = prices[i] - prices[i-1]
            for j in range(K, 0, -1):
                local[j] = max(glob[j-1]+max(diff,0), local[j]+diff)
                glob[j] = max(local[j], glob[j])
                
        return glob[K]


test = Solution()
K =2
prices= [4,4,6,1,1,4,2,5]
res = test.maxProfit(K, prices)
print(res)
