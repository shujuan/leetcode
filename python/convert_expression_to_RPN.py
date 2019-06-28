class Solution:
    """
    @param expression: A string array
    @return: The Reverse Polish notation of this expression
    """
    def convertToRPN(self, expression):
        # write your code here
        
        res = []
        st =[]
        
        for s in expression:
            if s ==')':
                while(st[-1] != '('):
                    res.append(st[-1])
                    st.pop()
                st.pop()
            elif s in '+-*/':
                while len(st) and self.getLevel(st[-1]) >= self.getLevel(s) :
                    res.append(st[-1])
                    st.pop()
                st.append(s)
            else:
                st.append(s)
                
        while len(st) :
            res.append(st[-1])
            st.pop()
        return res
        
    def getLevel(self, s):
        if s =='(' :
            return 1 
        elif s in '+-':
            return 2
        elif s in '/*':
            return 3
        else:
            return 4

test = Solution()
expression = "3-4+5"
res = test.convertToRPN(expression)
print(res)
