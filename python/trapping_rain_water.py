class Solution:
    """
    @param heights: a list of integers
    @return: a integer
    """
    def trapRainWater(self, heights):
        # write your code here
        stack = []
        
        i=0
        res = 0
        while i < len(heights):
            if len(stack)==0 or heights[i] < heights[stack[-1]]:
                stack.append(i)
                i +=1 
            else:
                t = stack[-1]
                stack.pop()
                if len(stack) ==0:
                    continue
                res += (min(heights[i], heights[stack[-1]]) -heights[t]) * (i-stack[-1]-1)
                
        return res

test = Solution()
heights = [0,1,0]
res = test.trapRainWater(heights)
print(res)

