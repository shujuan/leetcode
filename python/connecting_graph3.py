class ConnectingGraph3:
    """
    @param a: An integer
    @param b: An integer
    @return: nothing
    """
    def __init__(self, n):
        self.cnt = n 
        self.father = {}
        for i in range(1,n+1) :
            self.father[i] = i 
    
    # def find(self, a):
    #     if (self.father[a] == a):
    #         return a
    #     return self.find(self.father[a])
        
        
        
    
    def find(self, node):
        path = []
        while node != self.father[node]:
            path.append(node)
            node = self.father[node]
        
        for n in path:
            self.father[n] = node
        return node
    
    
    def connect(self, a, b):
        # write your code here
        root_a = self.find(a)
        root_b = self.find(b)
        if (root_a != root_b) :
            self.father[root_a] = root_b
            self.cnt -= 1
        

    """
    @return: An integer
    """
    def query(self):
        return self.cnt
        # write your code here


test = ConnectingGraph3(5)
res = []
res.append(test.query())
test.connect(1,2)
res.append(test.query())

print(res)
