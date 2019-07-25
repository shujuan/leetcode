import java.util.*;
class Solution {
    public static void main(String[] args) {
        Solution test = new Solution();
        int[]nums = {-1,0,1,2, -1,-4};
        List<List<Integer>> lst = test.threeSum(nums);
        System.out.println(lst);
    }
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        if (n == 0)  return res;
        Arrays.sort(nums);
        for(int i=0; i<n-2; i++){
            while(i!=0 && i<n-2 && nums[i-1] == nums[i]) i++;
            int j=i+1, k=n-1;
            int target = -nums[i];
            while(j < k) {
                while(j!=i+1 && j<k && nums[j-1] == nums[j]) j++;
                if(j>=k) break;
                if (nums[j] + nums[k] > target) k--;
                else if(nums[j] +nums[k] < target) j++;
                else{
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                }
            }
        }
        return res;
    }
}
