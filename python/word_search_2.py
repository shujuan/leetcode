class TrieNode:
    def __init__(self):
        self.child = {}
        self.word = None
        



class Solution:
    """
    @param board: A list of lists of character
    @param words: A list of string
    @return: A list of string
    """
    def __init__(self) :
        self.root = TrieNode()
    
    
    def insertWord(self, w):
        tmp = self.root
        for c in w:
            if c not in tmp.child:
                tmp.child[c] = TrieNode()
            tmp = tmp.child[c]
        tmp.word = w
            
    def search(self, board, visited, node, x, y, res):
        if node is None:
            return
        if node.word:
            res.append(node.word)
            node.word = None
        
        dirs = [[-1,0], [1,0],[0,1],[0,-1]]
        visited[x][y] = True
        for dir in dirs:
            nx = x + dir[0]
            ny = y + dir[1]
            if 0<= nx < len(board) and 0<= ny < len(board[0]) and not visited[nx][ny]  :
                self.search(board, visited, node.child.get(board[nx][ny], None), nx, ny, res)
        visited[x][y] = False
    
    def wordSearchII(self, board, words):
        # write your code here
        if not board or not len(board):
            return []
            
   
        
        for w in words:
            self.insertWord(w)
        
        m = len(board)
        n = len(board[0])
    
        visited = [[False]*n for i in range(m)]
        res = []
        for i in range(m):
            for j in range(n):
            
                self.search(board, visited, self.root.child.get(board[i][j],None), i, j, res)
        
        return res


test = Solution()
board = ["doaf", "agai", "dcan"]
words = ["dog", "dad", "dbdg", "can", "again"]
res = test.wordSearchII(board, words)
print (res)
