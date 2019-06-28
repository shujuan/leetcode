import heapq

class Solution:
    """
    @param heights: a matrix of integers
    @return: an integer
    """
    def trapRainWater(self, heights):
        # write your code here
        if not heights:
            return 0
        self.initialize(heights)
        res = 0
        while self.borders:
            h, x, y = heapq.heappop(self.borders)
            for nx, ny in self.adjacent(x,y):
                res += max(0, h-heights[nx][ny])
                self.add(nx, ny, max(h, heights[nx][ny]))
                
        return res
 
        
    def initialize(self, heights):
        self.m = len(heights)
        self.n = len(heights[0])
        self.visited = set()
        self.borders =[]
        
        for i in range(self.m):
            self.add(i, 0, heights[i][0])
            self.add(i, self.n-1, heights[i][self.n-1])
            
        for j in range(self.n):
            self.add(0,j, heights[0][j])
            self.add(self.m-1, j, heights[self.m-1][j])
            
    def add(self,x, y, h):
        heapq.heappush(self.borders, (h, x, y))
        self.visited.add((x, y))
        
        
    def adjacent(self,x, y):
        adj = []
        for delta_x, delta_y in ((-1,0), (1,0), (0,1), (0,-1)):
            nx = x+ delta_x
            ny = y + delta_y
            
            if 0<=nx<self.m and 0<=ny<self.n and (nx, ny) not in self.visited:
                adj.append((nx, ny))
        return adj
        
test = Solution()
heights =[ [12,13,0,12],[13,4,13,12],[13,8,10,12],[12,13,12,12],[13,13,13,13]]
res = test.trapRainWater(heights)
print(res)
