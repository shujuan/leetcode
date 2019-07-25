import java.util.*;

class Solution {
    private static final String[] KEY = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
 
    public static void main(String[] args) {
        Solution test = new Solution();
        String digits = "23";
        List<String> res = test.letterCombinations(digits);
        System.out.println(res);
    }

   public List<String> letterCombinations(String digits) {
        
        List<String> res = new LinkedList<>();
        if(digits.length() == 0) return res;
        getComb(digits, "", 0, res);
        return res;
    }
    
    private void getComb(String digits, String prefix, int start, List<String> res) {
        if (start == digits.length()) {
            res.add(prefix);
            return;
        }
        String letter = KEY[digits.charAt(start)-'0'];
        for (int i=0; i<letter.length(); i++ ){
            getComb(digits, prefix+letter.charAt(i), start+1, res);
        }
    }
    
}
