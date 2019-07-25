import java.util.*;
class MinWindowSubstring {
    public static void main(String[] args) {
        String s = "ADOBECODEBANC";
        String t = "BANC";
        MinWindowSubstring test = new MinWindowSubstring();
        System.out.println(test.minWindow(s,t));

    }
    public String minWindow(String s, String t) {
        HashMap<Character, Integer>map = new HashMap<>();
        for(char a : t.toCharArray()) {
            map.put(a, map.getOrDefault(a,0)+1);
        }
        
        int left=0, start=0, minLen = Integer.MAX_VALUE, cnt=0;
        int n= t.length();
        for(int i=0; i<s.length(); i++) {
            char b = s.charAt(i);
            if(map.containsKey(b) ){
                map.put(b, map.get(b)-1);
                if(map.get(b)>=0) cnt++;
            }
            while(cnt == n) {
                if(minLen > i-left+1) {
                    minLen = i-left+1;
                    start = left;
                }
                if(map.containsKey(s.charAt(left))) {
                    map.put(s.charAt(left), map.get(s.charAt(left))+1);
                    if(map.get(s.charAt(left)) >0) cnt--;
                }
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, minLen+start);
    }
}
