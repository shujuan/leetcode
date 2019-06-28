class MinStack:
    
    def __init__(self):
        # do intialization if necessary
        self.stack1=[]
        self.stack2 =[]

    """
    @param: number: An integer
    @return: nothing
    """
    def push(self, number):
        # write your code here
        self.stack1.append(number)
        if not self.stack2 or self.stack2[-1] >= number:
            self.stack2.append(number)

    """
    @return: An integer
    """
    def pop(self):
        # write your code here
        res = self.stack1[-1]
        self.stack1.pop()
        if res == self.stack2[-1]:
            self.stack2.pop()
        return res

    """
    @return: An integer
    """
    def min(self):
        # write your code here
        return self.stack2[-1]

test = MinStack()
test.push(1)
test.push(3)
test.push(2)
res = test.min()
print(res)
