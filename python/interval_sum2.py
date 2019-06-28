
class SegmentTree(object):

    def __init__(self, start, end, sum=0):
        self.start = start
        self.end = end
        self.sum = sum
        self.left, self.right = None, None 

    @classmethod
    def build(cls, start, end, a):
        if start > end:
            return None
    	
        if start == end:
            return SegmentTree(start, end, a[start])

        node = SegmentTree(start, end, a[start])

        mid = int((start + end) / 2)
        node.left = cls.build(start, mid, a)
        node.right = cls.build(mid + 1, end, a)
        
        node.sum = (0 if node.left is None else node.left.sum) + (0 if node.right is None else node.right.sum)
        return node

    @classmethod
    def modify(cls, root, index, value):
        if root is None:
            return

        if root.start == root.end:
            root.sum = value
            return
    
        if root.left.end >= index:
            cls.modify(root.left, index, value)
        else:
            cls.modify(root.right, index, value)
        
        root.sum = (0 if root.left is None else root.left.sum) + (0 if root.right is None else root.right.sum)

    @classmethod
    def query(cls, root, start, end):
        if root.start > end or root.end < start:
            return 0
    
        if start <= root.start and root.end <= end:
            return root.sum
        
        return cls.query(root.left, start, end) +  \
               cls.query(root.right, start, end)


class Solution:	
    # @param A: An integer list
    def __init__(self, A):
        # write your code here
        self.root = SegmentTree.build(0, len(A)-1, A)
    

    # @param start, end: Indices
    # @return: The sum from start to end
    def query(self, start, end):
        # write your code here
        return SegmentTree.query(self.root, start, end)
    

    # @param index, value: modify A[index] to value.
    def modify(self, index, value):
        # write your code here
        SegmentTree.modify(self.root, index, value)


A = [1,2,7,8,5]
test = Solution(A)
res = []
res.append(test.query(0,2))
test.modify(0,4)
res.append(test.query(0,1))
test.modify(2,1)

print(res)
