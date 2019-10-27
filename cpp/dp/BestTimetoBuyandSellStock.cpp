class Solution {
    public int maxProfit(int[] prices) {
        int mini = Integer.MAX_VALUE;
        int res = 0;
        for(int p:prices) {
            res = Math.max(res, p-mini);
            mini = Math.min(mini, p);
        }
        return res;
    }
}