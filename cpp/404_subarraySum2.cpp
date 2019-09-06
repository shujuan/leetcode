class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        // write your code here
        int n = A.size();
        int res =0;
        
        vector<int>sum(n+1, 0);
        
        for(int i=1; i<=n; i++) {
            sum[i] = sum[i-1]+A[i-1];
        }
        int l=1, r=1;
        for(int i=0; i<n; i++){
            while(l<=n && (sum[l]-sum[i]) < start) l++;
            while(r<=n && (sum[r]-sum[i]) <=end) r++;
             r--;
            if(l>i)
                res+=(r- l+1); 
            
        }
   
        return res;
    }
};
