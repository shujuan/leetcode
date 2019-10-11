class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int lf =0, rt=0;
        int maxNum = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);
            if(maxNum > nums[i]) rt = i;
        }
        int minNum = INT_MAX;
        for(int i=nums.size()-1; i>=0; i--) {
            minNum = min(minNum, nums[i]);
            if(minNum < nums[i]) lf = i;
        }
        return (rt==lf) ? 0 : rt-lf+1;
    }
};