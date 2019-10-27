class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target+1, 0);
        dp[0]=1;
        for(int i=0; i<nums.size(); i++){
            for(int j= target; j>=nums[i]; j--) {
                int cnt = 1;
                while(j >= cnt*nums[i]){
                    dp[j] += dp[j-cnt*nums[i]];
                    cnt++;
                }
                    
            }
        }
        
        return dp.back();
    }
    

};