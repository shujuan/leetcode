import java.util.*;
class SimplifyPath {
    public static void main(String[] args) {
        SimplifyPath test = new SimplifyPath();
        String path = "/home/";
        System.out.println(test.simplifyPath(path));

    }
    public String simplifyPath(String path) {
        String[] tmp = path.split("/");
        Stack<String> st = new Stack<>();
        for(int i=0; i<tmp.length; i++) {
            if(!st.empty() && tmp[i].equals("..")) {
                st.pop();
            } else if(!tmp[i].equals(".") && !tmp[i].equals("..") && !tmp[i].equals("")) {
                st.push(tmp[i]);
                
            }
        }
        
        List<String> res = new ArrayList<>(st);
        return "/"+ String.join("/", res);
    }
}
