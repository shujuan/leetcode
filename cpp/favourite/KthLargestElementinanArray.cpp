class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n) return 0;
        int left = 0, right = n-1;
        while (true) {
            
            int pos = partition(nums, left, right);
            if(pos >k-1) right = pos-1;
            else if(pos < k-1) left = pos+1;
            else return nums[k-1];
        } 
        
    }
    
      int partition(vector<int>& nums, int left, int right) {
        int l = left+1, r = right;
        int pivot = nums[left];
        while(l<=r){
             if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
        
        
        
    }
    
//     int partition(vector<int>& nums, int start, int end) {
//         int mid = (start+end)/2;
//         int pivot = nums[mid];
//         while(start <= end){
//             if(nums[start] <pivot && nums[end] > pivot)
//                 swap(nums[start++], nums[end--]);
//             if (nums[start] >=pivot) start++;
//             if ( nums[end] <=pivot) end--;
//         }
//         return end+1;
//     }

};