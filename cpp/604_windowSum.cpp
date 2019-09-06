class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        vector<int>res;
        if(!n) return res;
        vector<int>sum(n, 0);
        sum[0]=nums[0];
        for(int i=1; i<n; i++) {
            sum[i] +=sum[i-1] + nums[i];
        }
        res.push_back(sum[k-1]);
        for(int i= k; i<n; i++) {
            res.push_back(sum[i]-sum[i-k]);
        }
        
        return res;
    }
};
