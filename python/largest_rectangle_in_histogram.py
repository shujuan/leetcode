class Solution:
    """
    @param height: A list of integer
    @return: The area of largest rectangle in the histogram
    """
    def largestRectangleArea(self, height):
        # write your code here
        if not height:
            return 0
        
        res =0
        st = []
        height.append(0)
        m = len(height)
        for i in range(m):
            if (len(st)==0 or height[st[-1]] < height[i]):
                st.append(i)
            else:
                while(len(st) != 0 and height[st[-1]] > height[i]):
                    tmp = st[-1]
                    st.pop()
                    wd = 0
                    if not len(st):
                        wd = i
                    else:
                        wd = i-st[-1]-1
                    res = max(res, height[tmp] * wd)
                st.append(i)
        return res

height = [2,1,5,6,2,3]

test = Solution()
res = test.largestRectangleArea(height)
print(res)

