class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // write your code here
        int cnt =0;
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
      
        
        int left =0, right = nums.size()-1;
        while(left < right) {
            if(nums[left]+ nums[right] <= target){
                cnt += right -left;
                left++;
            } else{
                right--;
            }
        }
        return cnt;
    }
};
