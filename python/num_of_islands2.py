"""
Definition for a point.
"""
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b



class Solution:
    """
    @param n: An integer
    @param m: An integer
    @param operators: an array of point
    @return: an integer array
    """
    def numIslands2(self, n, m, operators):
        # write your code here
        result = []
        self.cnt = 0
        self.visited = set()
        self.father = {}
        
        dirs =[[-1,0],[1,0],[0,1],[0,-1]]
        for op in operators:
            x, y = op.x, op.y
            if (x,y) in self.visited:
                result.append(self.cnt);
                continue
            self.visited.add((x,y))
            self.father[(x,y)]=(x,y)
            self.cnt +=1 
            for dir in dirs:
                nx,ny = x+dir[0], y+dir[1]
                if (nx,ny) in self.visited:
                    self.connect((x,y), (nx, ny))
            result.append(self.cnt)
            
        return result
        
    def connect(self, point_a, point_b) :
        root_a = self.find(point_a)
        root_b = self.find(point_b)
        if root_a != root_b:
            self.father[root_b] = root_a
            self.cnt -=1 
            
            
    def find(self, point):
        # if point != self.father[point]:
        #     return self.find(self.father[point])
        # return point
        path = []
        while point != self.father[point]:
            path.append(point)
            point = self.father[point]
            
        for p in path:
            self.father[p] = point
            
        return point



n,m= 4,5
operators =[]
operators.append(Point(1,1))
operators.append(Point(0,1))
test=Solution()
res = test.numIslands2(n, m, operators)
print(res)

