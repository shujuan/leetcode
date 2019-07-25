import java.util.* ;

class SummaryRanges {
    public static void main(String[] args) {
        SummaryRanges test = new SummaryRanges();
        int[]nums = {0,1,2,4,5,7};
        System.out.println(test.summaryRanges(nums));
    }

    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList();
        int n = nums.length;
        if(n==0) return res;
        int start = 0;
        while(start < n) {
            int end = start+1;
            while(end<n && nums[end-1] +1== nums[end]) end +=1;
            if(start == end-1) {
                res.add(Integer.toString(nums[start]));
            } else {
                res.add(Integer.toString(nums[start]) + "->" + Integer.toString(nums[end-1]));
            }
            start = end;
        }
        
        return res;
    }
}
