class Solution {
public:
    /**
     * @param A: an integer array sorted in ascending order
     * @param target: An integer
     * @return: an integer
     */
    int closestNumber(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        if(!n) return -1;
        int left = 0, right = n-1;
        int minInd =-1, minDiff = INT_MAX;
        while(left<=right) {
            int mid = (left + right)/2;
            if(abs(target-A[mid]) < minDiff){
                minInd = mid;
                minDiff = abs(target-A[mid]);
            }
            if(A[mid] > target) {
                right = mid-1;
            } else if(A[mid < target]){
                left = mid+1;
            } else{
                return minInd;
            }
        }
        
        return minInd;
    }
};
