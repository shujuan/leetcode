class Solution:
    """
    @param source : A string
    @param target: A string
    @return: A string denote the minimum window, return "" if there is no such a string
    """
    def minWindow(self, source , target):
        # write your code here
        if len(source) == 0:
            return ""
        wordCount ={}
        for c in target:
            wordCount[c] = wordCount.get(c,0) + 1;
        
        lf, cnt,res = 0, 0, len(source)+1
        n = len(target)
        s = ""
       
        for i in range(len(source)):
            
            wordCount[source[i]] = wordCount.get(source[i],0) -1
            if wordCount[source[i]] >= 0:
                cnt += 1 
            
            while cnt == n:
                if i-lf+1 < res:
                    res = i-lf+1 
                    s = source[lf:i+1]
                wordCount[source[lf]] = wordCount.get(source[lf],0) +1 
                if wordCount[source[lf]] > 0 :
                    cnt -=1 
                lf += 1 
                
        if res == len(source)+1:
            return ""
        return s



test = Solution()
source = "ADOBECODEBANC"
target = "ABC"
res = test.minWindow(source, target)
print(res)

