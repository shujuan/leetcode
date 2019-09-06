class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param k: an integer
     * @return: the largest sum
     */
    int maxSubarray4(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        if(n<k) return 0;
        int sum=0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        int maxSum = sum;
        int minSum = 0;
        int preSum =0;
        for(int i=k; i<n; i++) {
            sum +=nums[i];
            preSum +=nums[i-k];
            minSum = min(minSum, preSum);
            maxSum = max(maxSum, sum-minSum);
        }
        return maxSum;
        
    }
};
