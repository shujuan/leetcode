class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int minNum = nums[0], maxNum=nums[0];
        int res = maxNum;
        for(int i=1; i<nums.size(); i++) {
            int preMin = minNum, preMax = maxNum;
            maxNum = max(nums[i], max(preMin*nums[i], preMax*nums[i]));
            minNum = min(nums[i], min(preMin*nums[i], preMax*nums[i]));
            res = max(maxNum, res);
        }
        return res;
        
    }
};