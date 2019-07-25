class MinSubArraySum {
    public static void main(String[] args) {
        MinSubArraySum test = new MinSubArraySum();
        int s = 7;
        int[]nums= {2,3,1,2,4,3};
        System.out.println(test.minSubArrayLen(s, nums));
    }
    public int minSubArrayLen(int s, int[] nums) {
        int start = 0, minLen = Integer.MAX_VALUE, sum = 0;
        for(int i=0; i<nums.length; i++) {
            sum += nums[i];
            while(start <= i && sum >= s) {
                minLen = Math.min(minLen, i-start+1);
                sum -= nums[start];
                start +=1;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
}
