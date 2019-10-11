class Solution {
    vector<char>ops = {'+', '-', '*', '/'};
    double eps = 1e-5;
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double>tmp(nums.begin(), nums.end());
        return get24(tmp);
    }
    
    bool get24(vector<double>& nums){
        int m = nums.size();
        if(m ==1) return abs(nums[0]-24)<eps;
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                if(i==j) continue;
                vector<double>tmp;
                for(int k=0; k<m; k++){
                    if(k!=i && k!=j) {
                        tmp.push_back(nums[k]);
                    }
                }
                for(auto op : ops) {
                    if((op == '*' || op == '+') && i>j)continue;
                    if(op == '/' && nums[j] <eps) continue;
                    if(op == '+') tmp.push_back(nums[i]+nums[j]);
                    else if(op == '-') tmp.push_back(nums[i]-nums[j]);
                    else if(op == '*') tmp.push_back(nums[i]*nums[j]);
                    else {
                        tmp.push_back(nums[i]/nums[j]);
                    }
                    
                    if(get24(tmp)) return true;
                    tmp.pop_back();
                }
            }
        }
        
        return false;
    }
};