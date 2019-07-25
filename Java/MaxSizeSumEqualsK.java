import java.util.*;
class MaxSum {
    public static void main(String[] args) {
        MaxSum test = new MaxSum();
        int[] nums ={1,-1,5,-2, 3};
        int k = 3;
        System.out.println(test.maxSubArrayLen(nums, k));
    }
    public int maxSubArrayLen(int[] nums, int k) {
        HashMap<Integer, Integer> sum = new HashMap<>();
        int n = nums.length;
        if(n==0) return 0;
        sum.put(0, -1);
        int curSum = 0, res =0;
        for(int i=0; i<n; i++){
            curSum += nums[i];
            if(sum.containsKey(curSum) == false) {
                sum.put(curSum, i);
            }
            if(sum.containsKey(curSum - k)) {
                res = Math.max(res, i - sum.get(curSum-k));
            }
        }
        return res;
    }
}
