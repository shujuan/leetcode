class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>>dp(n, vector<string>(n));
        // for(int i=0; i<n; i++) {
        //     dp[i][i]=s[i];
        // }
        
        for(int len = 1; len<=n; len++) {
            for(int i =0; i+len<=n; i++) {
                int j= i+len-1;
                string t = s.substr(i,len);
                dp[i][j] = t;
                string tmp = t+t;
                int pos = tmp.find(t, 1);
                if(pos < t.size()) {
                    string str = to_string(t.size()/pos) + "["+ dp[i][i+pos-1] +"]";
                    if(str.size() < t.size()) dp[i][j] = str;
                    continue;
                }
                
                for(int k=i; k<j; k++){
                    if(dp[i][j].size() > dp[i][k].size() + dp[k+1][j].size()){
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                    }
                }
                
                
                
            }
        }
        
        return dp[0][n-1];
    }
};