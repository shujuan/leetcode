class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>sums;
        sums.insert({0,1});
        int sum =0, res=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            if(sums.count(sum-k))res+=sums[sum-k];
            sums[sum]++;
        }
        return res;
    }
};