class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n) return false;
        unordered_set<int>st;
        int sum = 0, pre=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int mod = k==0 ? sum : (sum%k);
            if(st.count(mod)) return true;
            st.insert(pre);
            pre = mod;
        }
        return false;
    }
};