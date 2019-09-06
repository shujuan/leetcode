class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        
        int left =0, right = nums.size()-1;
        
        while(left <=right) {
            int mid = (left +right)/2;
            if(nums[mid]<=target) {
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        if(right>=0 && nums[right] == target) return right;
        else return -1;
    }
};
