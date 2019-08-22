class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        // write your code here
        
        return quickSelect(nums, 0, nums.size()-1, k-1);
       
    }
    
    
    int quickSelect(vector<int>& nums, int start, int end, int k) {
        int i=start, j= end;
        
        int pivot = nums[(start+end)/2];
        if(i == j) return pivot;
        while(i<=j){
            while(i<=j && nums[i] <pivot) i++;
            while(i<=j && nums[j] > pivot) j--;
            if(i<=j) {
                swap(nums[i++], nums[j--]);
            }
        }
       
        if(j>=k && start <= j) return quickSelect(nums, start, j, k);
        else if(i<=k && end >=i) return quickSelect(nums, i, end, k);
        else return pivot;
        
        
    }
};
