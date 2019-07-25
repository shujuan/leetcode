import java.util.*;
class RemoveInvalidParentheses {
    public static void main(String[] args) {
        String s = "()())()";
        RemoveInvalidParentheses test = new RemoveInvalidParentheses();
        System.out.println(test.removeInvalidParentheses(s));



    }
    public List<String> removeInvalidParentheses(String s) {
        List<String> res = new ArrayList<>();
        int cnt1=0, cnt2=0;
        if (s == null) return Arrays.asList("");
        //if(s.length() == 0) return res;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '(') cnt1++;
            else if(s.charAt(i) == ')') {
                if(cnt1>0) cnt1--;
                else cnt2++;
            }
        }
        
        getParenth(s, 0, cnt1, cnt2, res);
        return res;
    }
    
    void getParenth(String s, int start, int cnt1, int cnt2, List<String> res){
        if(cnt1==0 && cnt2==0){
            if(isValid(s)){
                res.add(s);
            }
            return;
        }
        
        for(int i=start; i<s.length(); i++) {
            if(i!=start && s.charAt(i-1) == s.charAt(i)) continue;
            if(cnt1>0 && s.charAt(i)== '(') {
                getParenth(s.substring(0, i)+s.substring(i+1), i, cnt1-1, cnt2, res);
            }
            if(cnt2>0 && s.charAt(i) == ')') {
                getParenth(s.substring(0, i)+s.substring(i+1), i, cnt1, cnt2-1, res);
            }
        }
        
    }
    
    boolean isValid(String s) {
        int cnt1 =0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '(') cnt1++;
            else if(s.charAt(i) == ')'){
                if(cnt1>0) cnt1--;
                else return false;
            }
        }
        return cnt1==0;
    }
    

    
}
