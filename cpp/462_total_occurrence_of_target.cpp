class Solution {
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        if(!n) return 0;
        int left =0, right = n-1;
        while(left<=right) {
            int mid = (left+right)/2;
            if(A[mid] <target){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        if(A[left] != target) return 0;
        int res =0;
        while(left <n) {
           
            if(A[left++] != target) break;
            res++;
        }
        return res;
    }
};
