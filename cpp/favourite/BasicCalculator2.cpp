class Solution {
public:
    int calculate(string s) {
        int res=0;
        int i=0, n = s.size();
        char op = '+';
        int tmp = 0, num=0;
        while(i<n) {
           
            while(i<n && s[i]>='0' && s[i]<='9') {
                num = 10*num + (s[i] - '0');
                i++;
            }
            if (i==n) i--;
    
            if (s[i]=='+' || s[i]=='-' || s[i]=='*' ||s[i]=='/' ||i==n-1) {
                switch(op){
                    case '+' : tmp +=num;
                    break;
                    case '-' : tmp -=num;
                    break;
                    case '*' : tmp *=num;
                    break;
                    case '/' : tmp /=num;  
                    break;
                }
                if(s[i] == '+' || s[i]=='-' || i==n-1) {
                    res += tmp;
                    tmp = 0;
                }
                op = s[i];
                num = 0;
            }
            i++;
            
        }
        
        return res;
    }
};