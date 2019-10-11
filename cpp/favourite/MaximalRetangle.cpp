class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        // write your code here
        int m = matrix.size();
        int res =0;
        if(!m) return res;
        int n = matrix[0].size();
        vector<int>col(n+1,0);
        
        for (int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!matrix[i][j]) col[j] =0;
                else col[j] +=1;
            }
            stack<int>st;
            for(int j=0; j<=n; j++) {
                if(st.empty() || col[st.top()]< col[j]) st.push(j);
                else{
                    while(!st.empty() && col[st.top()] > col[j]) {
                        int tmp = st.top();
                        st.pop();
                        res = max(res, col[tmp]*(st.empty()? j : (j-st.top() -1)));
                    }
                    st.push(j);
                }
            }
        }
        return res;
    }
    

};