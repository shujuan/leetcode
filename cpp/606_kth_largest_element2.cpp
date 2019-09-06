class Solution {
public:
    /**
     * @param nums: an integer unsorted array
     * @param k: an integer from 1 to n
     * @return: the kth largest element
     */
    int kthLargestElement2(vector<int> &nums, int k) {
        // write your code here
        int start = 0, end = nums.size()-1;
        while(true){
           // if(start == end) return nums[start];
            int left =start, right = end;
            
            int pivot = nums[(left+right)/2];
            while(left <= right) {
                // if(nums[left] < pivot && nums[right] >pivot)  {
                //     swap(nums[left++], nums[right--]);
                    
                // }
                while(left <=right && nums[left] > pivot) left++;
                while(left<=right && nums[right] <pivot) right--;
                if(left<=right) swap(nums[left++], nums[right--]);
                
            }
           // swap(nums[start], nums[right]);
            //cout <<left<<right<<'\n';
            // if(right == k-1) return pivot;
            // else if(right > k-1){
            //     end = right-1;
            // } else {
            //     start = right+1;
            // }
            if(right>=k-1 && start <= right) {
                end = right;
            } else if(left <=k-1 && end >= left){
                start = left;
            } else{
                return nums[k-1];
            }
            
            
        }
       
    }
};
