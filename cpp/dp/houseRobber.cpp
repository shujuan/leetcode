class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n==1) return nums[0];
        return max(getMax(0,n-1,nums), getMax(1,n,nums));
    }
    
    int getMax(int start, int end, vector<int>& nums){
        int n = end-start;
        vector<int>dp(n+1,0);
        dp[1]= nums[start];
        for(int i=2; i<=n; i++) {
            dp[i] = max(nums[start+i-1]+dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
};
