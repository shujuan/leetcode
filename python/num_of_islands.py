
from collections import deque
class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    def numIslands(self, grid):
        # write your code here
        if not grid or not grid[0]:
            return 0
        
        m, n = len(grid), len(grid[0])
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    self.bfs(grid, i, j)
                    res +=1 
                    
        return res
        
        
    def bfs(self, grid, i, j):
        q = deque([(i,j)])
        dirs =[(-1,0), (1,0), (0,1), (0,-1)]
        while len(q) :
            x, y = q.popleft()
            for delta_x, delta_y in dirs :
                next_x = x+delta_x
                next_y = y + delta_y
                if 0<= next_x < len(grid) and 0<=next_y<len(grid[0]) and grid[next_x][next_y]:
                    q.append((next_x, next_y))
                    grid[next_x][next_y]=0

test = Solution()
grid = [[1,1,0,0,0],[0,1,0,0,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,0,0,1]]
res = test.numIslands(grid)
print(res)
