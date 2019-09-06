class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int left =0, right = nums.size()-1;
        while(left <right) {
            if(abs(target - (nums[left] + nums[right])) < minDiff){
                    minDiff = abs(target - (nums[left] + nums[right]));
            }
            if(nums[left] + nums[right] < target){
               
                left++;
            } else if(nums[left] + nums[right] > target) {
                right--;
            } else {
                return 0;
            }
        }
        
        return minDiff;
    }
};
