class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int>tmp;
        vector<int>res;
        for(int i=0; i<nums.size(); i++) {
            if(tmp.count(target-nums[i])){
                res.push_back(tmp[target-nums[i]]);
                res.push_back(i);
                
            }
            tmp[nums[i]]=i;
        }
        return res;
        
    }
};