class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<vector<int>> res;
        if(n<=1) return res;
        vector<int> tmp;
        helper(n, tmp, 2, res);
        return res;
    }
    
    void helper(int n, vector<int>& tmp, int start, vector<vector<int>>& res) {
       
        for(int i= start; i<= (int)sqrt(n); i++){
            vector<int>newOut = tmp;
            if(n%i == 0){
                newOut.push_back(i);
                //cout<<i<<' '<<n<<'\n';
                helper(n/i, newOut, i, res);
                newOut.push_back(n/i);
                res.push_back(newOut);
            } 
        }
        
    }
};
