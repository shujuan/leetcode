"""
Definition of TreeNode:
""" 
import sys 
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def maxPathSum(self, root):
        # write your code here
        res, tmp = self.getMax(root)
        
        return res
        
    def getMax(self, root):
        if root is None:
            return -sys.maxsize-1, 0
        left = self.getMax(root.left)
        right = self.getMax(root.right)
        res = max(left[0], right[0], left[1]+right[1]+root.val)
        tmp = max(left[1]+root.val, right[1]+root.val, 0)
        
        return res,tmp

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

test=Solution()
res = test.maxPathSum(root)
print(res)
