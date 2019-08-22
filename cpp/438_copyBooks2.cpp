class Solution {
public:
    /**
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        // write your code here
        int sz = times.size();
        int left =0, right = n*times[0];
        while(left <= right){
            int mid = (left + right)/2;
            if(count(times, mid) >=n){
                right = mid-1;
            } else if(count(times, mid) < n) {
                left = mid+1;
            }
            // else {
            //     return mid;
            // }
        }
        
        return left;
    }
    
    int count(vector<int>& times, int period){
        int res =0;
        for(auto t : times) {
            res += period/t;
        }
        return res;
    }
};
