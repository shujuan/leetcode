class Solution:
    """
    @param: A: Given an integer array
    @return: nothing
    """
    def heapify(self, A):
        # write your code here
        for i in range(len(A)//2, -1,-1):
            self.siftdown(i, A)
        
        
    def siftdown(self, i, A):
        smallest = i
        left = 2*i +1 
        right = 2*i +2 
        
        if left < len(A) and A[left] < A[smallest]:
            smallest = left
        if right < len(A) and A[right] < A[smallest]:
            smallest = right
        
        if smallest != i :
            A[smallest] , A[i] = A[i], A[smallest]
            self.siftdown(smallest, A)

test = Solution()
A = [3,2,1,4,5]
test.heapify(A)
print(A)

