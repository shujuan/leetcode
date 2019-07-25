import java.util.*;
class Solution {
    static public void main(String[] args){
        Solution test = new Solution();
        int[] nums={100, 4, 200, 1, 3, 2};
        int res = test.longestConsecutive(nums);
        System.out.println(res);
    }

    public int longestConsecutive(int[] nums) {
        if(nums==null || nums.length==0) return 0;
        Set<Integer> st = new HashSet<Integer>();
        for(int num : nums) st.add(num);
        int res=1;
        for(int num:nums) {
            if(st.remove(num)){
                int pre=num-1;
                int post= num+1;
                while(st.remove(pre)) pre--;
                while(st.remove(post)) post++;
                res = Math.max(res, post-pre-1);
                
            }
        }
        return res;
        
    }
}

