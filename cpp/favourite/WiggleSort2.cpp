class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp=nums;
        int n = nums.size();
        sort(tmp.begin(), tmp.end());
        int k =(n+1)/2, j = n;
        for(int i=0; i<n; i++) {
            nums[i] = i%2 ? tmp[--j] : tmp[--k];
     
        }
     
        
    }
};