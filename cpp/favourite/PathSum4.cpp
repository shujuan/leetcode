class Solution {
    int res=0;
public:
    int pathSum(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<vector<int>>vals(4,vector<int>(8,-1));
        for(auto num :nums) {
            int row = num/100 -1;
            int col = (num%100)/10 -1;
            vals[row][col] = num%10;
        }
        int tmp =0;
        getSum(vals, 0, 0, tmp);
        return res;
        
    }
    
    void getSum(vector<vector<int>>& vals, int r, int c, int pathVal) {
        
        if(vals[r][c] ==-1) return;
        pathVal +=vals[r][c];
        if((r+1)>= vals.size() || (2*c +1)>= vals[0].size()|| (vals[r+1][2*c] ==-1 && vals[r+1][2*c+1] ==-1)){
            res +=pathVal;
            return;
        } 
        getSum(vals, r+1, 2*c, pathVal);
        getSum(vals, r+1, 2*c+1, pathVal);
        
    }
};