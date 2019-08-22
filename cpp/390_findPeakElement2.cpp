class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        // write your code here
        int m= A.size(), n = A[0].size();
        vector<int>res;
        if(m<=2 || n<=2) return res;
        for(int i=1; i<m-1; i++) {
            int j = findCol(A[i]);
            if(A[i][j] > A[i-1][j] && A[i][j] > A[i+1][j]) return vector<int>{i, j};
        }
        
    }
    
    int findCol(vector<int> v){
        int left=1, right = v.size()-2;
        
        while(left <right) {
            int mid = (left+right)/2;
            if(v[mid]<v[mid+1]){
                left = mid+1;
            } else{
                right = mid;
            }
        }
        return left;
    }
    
    
};
