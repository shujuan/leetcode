class Solution:
    """
    @param s: the given string
    @return: if the starting player can guarantee a win
    """
    def __init__(self):
        self.memo = {}
        
    def canWin(self, s):
        # write your code here
        n = len(s)
        for i in range(1, n):
            if s[i] == '+' and s[i-1] == '+':
                tmp = s[:i-1] +"--"+s[i+1:]
                win = False
                if tmp in self.memo:
                    win = self.memo[tmp]
                else:
                    win = self.canWin(tmp)
                    self.memo[tmp] = win
            
                if not win:
                    return True
        self.memo[s] = False
        return False
        
s = "++++++++"
test = Solution()
res = test.canWin(s)

print(res)
