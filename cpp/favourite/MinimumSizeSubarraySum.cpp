class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res =INT_MAX;
        int n=nums.size();
        if(!n) return 0;
        int sum =0, start=0;
        for(int i=0; i<n; i++) {
            sum +=nums[i];
            while(sum>=s &&start<=i) {
                res = min(res, i-start+1);
                sum -=nums[start++];
                
            }
        }
        
        return res==INT_MAX? 0:res;
    }
};