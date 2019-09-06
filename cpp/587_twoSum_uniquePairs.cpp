class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int res = 0;
        int left =0, right = nums.size()-1;
        while(left<right) {
            if(left!=0 && nums[left] == nums[left-1]) {
                left++;
                continue;
            }
            if(right!=nums.size()-1 && nums[right] == nums[right+1]){
                right--;
                continue;
            }
            if(nums[left] + nums[right] < target){
                left++;
            }else if(nums[left] + nums[right] > target) {
                right--;
            } else {
                //cout<<left<< " "<<right<<"\n";
                res++;
                left++;
                right--;
            }
           
            
        }
        return res;
    }
    
    
};
