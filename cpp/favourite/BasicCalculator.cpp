class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int num=0, res=0;
        int sign = 1;
        stack<int>st;
        for(int i=0; i<n; i++) {
            if(s[i] >='0') {
                while(i<n && s[i] >='0') {
                    num = num*10 + (s[i++] - '0');
                }
                i--;
  
            } else if(s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
    
            } else if(s[i] == ')') {
                res+= num*sign;
                num=0;
                sign=1;
                if(!st.empty()){
                    auto t = st.top();
                    st.pop();
                    res *= t;
                    t = st.top();
                    st.pop();
                    res += t;
                }
                
                
            } else if(s[i] == '+' || s[i] == '-') {
                res += num*sign;
                num = 0;
                sign = s[i] == '+' ? 1 : -1; 
            }
        }
        
        res += num*sign;
        return res;
        
    }
};