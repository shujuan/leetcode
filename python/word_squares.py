class TrieNode:
    def __init__(self):
        self.prefix = []
        self.child ={}


class Solution:
    """
    @param: words: a set of words without duplicates
    @return: all word squares
    """
    def __init__(self):
        self.root = TrieNode()
        
    def buildTrie(self, words):
        for i in range(len(words)):
            tmp = self.root
            for j in range(len(words[i])) :
                if words[i][j] not in tmp.child:
                    tmp.child[words[i][j]] = TrieNode()
                tmp.prefix.append(i)
                tmp = tmp.child[words[i][j]]
    
    
    def wordSquares(self, words):
        # write your code here
        res = []
        if not words or not words[0]:
            return res
            
        self.buildTrie(words)
        
        out = []
        for i in range(len(words)):
            out.append(words[i])
            self.getPrefix(words, out, res)
            out.pop()
            
        return res
        
    
    def getPrefix(self, words, out, res):
        if len(out) == len(words[0]):
         
            res.append(list(out))
            return
       
        n = len(out)
        # for i in len(out):
        #     target += out[i][n]
            
        target = ''.join([out[i][n] for i in range(n)])
        
        tmp = self.root
        for j in range(len(target)) :
            if target[j] not in tmp.child :
                return
            tmp = tmp.child[target[j]]
        
        for k in range(len(tmp.prefix)):
            out.append(words[tmp.prefix[k]])
            self.getPrefix(words, out, res)
            out.pop()
            
        
test = Solution()
words = ["area", "lead", "wall", "lady", "ball"]
res = test.wordSquares(words)
print(res)

