class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res=0;
        for (int i=0; i<32; i++) {
            int cnt1 = 0, cnt2 = 0, bit = 1<<i;
            for (int k=0; k<nums.size(); k++) {
                if (k & bit) cnt1++;
                if (nums[k] & bit) cnt2++;
            }
            if (cnt1 < cnt2) res +=bit;
        }
        return res;
    }
};