import java.util.*;
class GroupAnagram {
    public static void main(String[] args) {
        GroupAnagram test = new GroupAnagram();
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        System.out.println(test.groupAnagrams(strs));

    }

    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>>map = new HashMap<>();
        int n = strs.length;
        if(n==0) return new ArrayList<>();
        for(int i=0; i<n; i++) {
            char[] tmp = strs[i].toCharArray();
            Arrays.sort(tmp);
            String t = new String(tmp);
            map.putIfAbsent(t, new ArrayList<String>());
            List<String> st = map.get(t);
            st.add(strs[i]);
        }
        
        return new ArrayList<>(map.values());
        
    }
}
