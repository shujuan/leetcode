class Solution {
    public static void main(String[] args){
        Solution test = new Solution();
        String s = "ab", t = "acb";
        boolean res = test.isOneEditDistance(s, t);
        System.out.println(res);
    }

    public boolean isOneEditDistance(String s, String t) {
        int m = s.length(), n = t.length();
        if(m > n) return isOneEditDistance(t, s);
        if((n-m)>1) return false;
        boolean edit = true;
        for(int i=0; i<m; i++){
            if(s.charAt(i) != t.charAt(i)) {
                edit = false;
                if(m == n) {
                    s = s.substring(0,i) + t.charAt(i) + s.substring(i+1);
                } else{
                    s = s.substring(0, i) + t.charAt(i) + s.substring(i);
                }
                break; 
            }
        } 
        
        return ((edit && n-m == 1) || (!edit && s.equals(t)));
    }
}

