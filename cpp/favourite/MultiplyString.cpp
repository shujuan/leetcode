class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int m= num1.size(), n=num2.size();
        vector<int>val(m+n);
        for (int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--){
                int p1=i+j, p2=i+j+1;
                int sum = (num1[i]-'0')*(num2[j]-'0') + val[p2];
                val[p2] = sum%10;
                val[p1] += sum/10; 
            }
        }
        for(int i=0; i<m+n; i++){
            if(!res.empty()||val[i]) {
                res+= ('0'+val[i]);
            }
        }
        
        return res.empty()?"0":res;
        
    }
};