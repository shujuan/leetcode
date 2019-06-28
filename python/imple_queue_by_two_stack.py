class MyQueue:
    
    def __init__(self):
        # do intialization if necessary
        self.stack1=[]
        self.stack2=[]

    """
    @param: element: An integer
    @return: nothing
    """
    def push(self, element):
        # write your code here
        self.stack1.append(element)

    """
    @return: An integer
    """
    def pop(self):
        # write your code here
        res = self.top()
        self.stack2.pop()
        return res

    """
    @return: An integer
    """
    def top(self):
        # write your code here
        if(len(self.stack2)):
            return self.stack2[-1]
        while(len(self.stack1)):
            self.stack2.append(self.stack1[-1])
            self.stack1.pop()
        return self.stack2[-1]


test = MyQueue()
test.push(1)
res = test.pop()
print(res)
