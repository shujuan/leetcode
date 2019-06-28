class TrieNode:
    def __init__(self) :
        self.isword = False
        self.child = {}



class WordDictionary:
    """
    @param: word: Adds a word into the data structure.
    @return: nothing
    """
    def __init__(self):
        self.root = TrieNode()
        
    def addWord(self, word):
        # write your code here
        tmp = self.root
        for w in word:
            if w not in tmp.child:
                tmp.child[w] = TrieNode()
            tmp = tmp.child[w]
        tmp.isword = True

    """
    @param: word: A word could contain the dot character '.' to represent any one letter.
    @return: if the word is in the data structure.
    """
    def search(self, word):
        # write your code here
        tmp = self.root
        return self.search_node(word, 0, tmp)
        
        
    def search_node(self, word, pos, tmp):
        if tmp is None:
            return False
        if pos == len(word):
            return tmp.isword
        
        if word[pos] == '.' :
            for u,v in tmp.child.items():
                if (self.search_node(word, pos+1, v)):
                    return True
        else:
            if word[pos] in tmp.child:
                return self.search_node(word, pos+1, tmp.child[word[pos]])
                
        return False
  
test = WordDictionary()
test.addWord("a")
res = test.search(".")
print(res)

