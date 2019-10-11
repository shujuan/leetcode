class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        if(n<1) return res;
        int Xor = 0;
        int tmp = 0;
        for (int i=0; i<n; i++) {
            tmp ^= nums[i];
        }
        int bit = tmp &(~(tmp-1));

        
        int num1=0, num2=0;
        for (int i=0;i<n; i++) {
            if(nums[i]&bit) {
                num1 ^=nums[i];
            } else {
                num2 ^=nums[i];
            }
        }

        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
};