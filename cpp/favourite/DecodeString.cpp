class Solution {
public:
    string decodeString(string s) {
        stack<int>st_num;
        stack<string>st_str;
        string t;
        int cnt=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]>='0' && s[i] <='9'){
                cnt = cnt*10 +s[i]-'0';
            } else if(s[i] == '[') {
                st_num.push(cnt);
                cnt=0;
                st_str.push(t);
                t.clear();
            } else if(s[i] ==']') {
                int k = st_num.top();
                st_num.pop();
                for(int i=0; i<k; i++) st_str.top()+=t;
                t = st_str.top();
                st_str.pop();
            } else {
                t += s[i];
            }
        }
        
        return t;
    }
};