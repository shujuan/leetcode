class Solution {
public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        // write your code here
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>up(m, vector<int>(n, 0));
        vector<vector<int>>down(m, vector<int>(n, 0));
        vector<vector<int>>f(m, vector<int>(n,0));
        int res = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]==0){
                    f[i][j] =0;
                    up[i][j] = down[i][j] =1;
                    if(i>0) up[i][j] = up[i-1][j]+1;
                    if(j>0) down[i][j] = down[i][j-1] +1;
                } else{
                    up[i][j] = down[i][j] = 0;
                    if(i>0&& j>0){
                        f[i][j] = min(f[i-1][j-1], min(up[i-1][j], down[i][j-1])) +1;
                    } else {
                        f[i][j] = 1;
                    }
                    res = max(f[i][j], res);
                }
            }
        }
        return res*res;
    }
};
