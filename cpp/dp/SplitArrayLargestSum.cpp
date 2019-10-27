class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long>sub(n+1, 0);
        vector<vector<long long>>f(n+1, vector<long long>(m+1, INT_MAX));
        f[0][0] =0;
        for(int i=1; i<=n; i++)
            sub[i] +=sub[i-1]+nums[i-1];
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                for(int k =0; k<i; k++){
                    f[i][j] = min(f[i][j], max(f[k][j-1], sub[i]-sub[k]));
                    
                }
                
            }
        }
        return (int)f[n][m];

    }
    
    

    
};