class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        if(!n) return res;
        vector<int>visited(n, false);
        vector<int> out;
        getPermute(nums, out, visited, res);
        return res;
        
    }
    
    void getPermute(vector<int>& nums, vector<int>& out, vector<int>& visited, vector<vector<int>>& res){
        if(out.size() == nums.size()){
            res.push_back(out);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(visited[i]) continue;
            visited[i] = true;
            out.push_back(nums[i]);
            getPermute(nums,out, visited, res );
            out.pop_back();
            visited[i] = false;
        }
    }
};