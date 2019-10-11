class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        int zero = 0, one = 0;
        int len =0;
        m[0] = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) zero++;
            else one++;
            if(m.count(zero-one)) len = max(len, i-m[zero-one]);
            else m[zero-one] = i;
        }
        
        return len;
    }
};