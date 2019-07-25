import java.util.HashMap;
class Solution {
    public static void main(String[] args){
        Solution test = new Solution();
        String s = "LVIII";
        int res = test.romanToInt(s);
        System.out.println(res);

    }

    public int romanToInt(String s) {
        HashMap<Character, Integer>mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
        int n = s.length();
        int res = mp.get(s.charAt(n-1));
        for (int i=n-1; i>0; i--) {
            int prev = mp.get(s.charAt(i-1));
            int cur = mp.get(s.charAt(i));
            if (prev >= cur) res += prev;
            else res -= prev;
        }
        return res;
    }
}
