import collections

class Solution:
    """
    @param n: An integer
    @param edges: a list of undirected edges
    @return: true if it's a valid tree, or false
    """
    def validTree(self, n, edges):
        # write your code here
        if len(edges) != n-1:
            return False
            
        neighbors = collections.defaultdict(list);
        for u, v in edges:
            neighbors[u].append(v)
            neighbors[v].append(u)
        visited = set([0])
        from queue import Queue
        q = Queue()
        q.put(0)
        
        while not q.empty() :
            cur = q.get()
            for node in neighbors[cur]:
                if node not in visited:
                    q.put(node)
                    visited.add(node)
                    
        return len(visited) == n


n = 5
edges = [[0,1],[0,2], [0,3],[1,4]]

test = Solution()
res = test.validTree(n, edges)
print(res)
