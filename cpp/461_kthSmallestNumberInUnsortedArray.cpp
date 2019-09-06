class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        // write your code here
        int start=0, end = nums.size()-1;
        while(start<=end) {
            int left = start+1, right = end;
            int pivot = nums[start];
            while(left<=right) {
                while(left<=right && nums[left] <= pivot) left++;
                while(left<=right && nums[right] >= pivot) right--;
                if(left <= right) swap(nums[left++], nums[right--]);
            }
            
            swap(nums[start], nums[right]);
            if(right == k-1) return pivot;
            else if(right >k-1) end = right-1;
            else start = right+1;
        }
        
    }
};
