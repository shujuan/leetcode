class Solution {
    public static void main(String[] args) {
       Solution test = new Solution();
       String s = "aa";
       String p = "a";
       boolean res = test.isMatch(s,p);
       System.out.println(res);

    }
    public boolean isMatch(String s, String p) {
        boolean[][]dp = new boolean[s.length()+1][p.length()+1];
        dp[0][0] = true;
        for (int i=0; i<=s.length(); i++){
            for (int j=1; j<=p.length(); j++){
                if(j>1 && p.charAt(j-1)== '*') {
                    dp[i][j] = dp[i][j-2] || (i>0 && dp[i-1][j] && (s.charAt(i-1) == p.charAt(j-2) || p.charAt(j-2) == '.') );
                } else {
                    dp[i][j] = i>0 && dp[i-1][j-1] && (s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) =='.');
                }
            }       
        }
        
        return dp[s.length()][p.length()];
    }
}

